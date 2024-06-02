#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>

class BroadcasterNode{
    private:
        //initilize ros
        ros::NodeHandle nh;
        ros::Subscriber sub_visp_status;
        ros::Subscriber sub_visp_name;
        ros::Subscriber sub_visp_distance;

        //TF
        tf::TransformBroadcaster br;
        std::string camera_frame_name;  

        //QR parameters
        int status_qr;
        std::string object_name;
        geometry_msgs::PoseStamped qr_pose;


    public:
        bool exec_flag;
        BroadcasterNode();
        void get_statusQR(std_msgs::Int8);
        void get_nameQR(std_msgs::String);
        void get_distanceQR(geometry_msgs::PoseStamped);
        void tf_broadcaster();
};

BroadcasterNode::BroadcasterNode(){
    this->sub_visp_status = nh.subscribe("/visp_auto_tracker/status",1,&BroadcasterNode::get_statusQR,this);
    this->sub_visp_name = nh.subscribe("/visp_auto_tracker/code_message",1,&BroadcasterNode::get_nameQR,this);
    this->sub_visp_distance = nh.subscribe("/visp_auto_tracker/object_position",1,&BroadcasterNode::get_distanceQR,this);
    ROS_INFO("tf_broadcaster initialize ok");
    if(exec_flag = true){
        //tf_broadcaster();
    }
}

void BroadcasterNode::get_statusQR(std_msgs::Int8 status){
    this->status_qr = status.data;
    //ROS_INFO("QR status: %s",status_qr);
    //std::cout << status_qr << std::endl;
    if(status_qr == 1) this->exec_flag = false;
}

void BroadcasterNode::get_nameQR(std_msgs::String qr_message){
    this->object_name = qr_message.data;
    //ROS_INFO("QR message: %s",status_qr);
    //std::cout << object_name << std::endl;
}

void BroadcasterNode::get_distanceQR(geometry_msgs::PoseStamped qr_distance){
    this->qr_pose = qr_distance;
    this->exec_flag = true;
    //ROS_INFO("QR pose: %ld",qr_pose);
    //std::cout << qr_pose << std::endl;
}

void BroadcasterNode::tf_broadcaster(){
    tf::Transform transform;
    //set position
    float obj_x = qr_pose.pose.position.x;
    float obj_y = qr_pose.pose.position.y;
    float obj_z = qr_pose.pose.position.z;
    transform.setOrigin(tf::Vector3(obj_x,obj_y,obj_z));
    
    //set rotation
    float rot_x = qr_pose.pose.orientation.x;
    float rot_y = qr_pose.pose.orientation.y;
    float rot_z = qr_pose.pose.orientation.z;
    float rot_w = qr_pose.pose.orientation.w;
    tf::Quaternion q;
    q.setValue(rot_x,rot_y,rot_z,rot_w);
    transform.setRotation(q);

    br.sendTransform(tf::StampedTransform(transform,ros::Time::now(),"head_rgb_camera_link",object_name));
}

int main(int argc, char *argv[]){
    ros::init(argc,argv,"tf_broadcaster_node");
    BroadcasterNode bcn;
    ros::Rate loop_rate(30);
    while(ros::ok()){  
        bcn.tf_broadcaster();
        loop_rate.sleep();
        ros::spinOnce();
    }
}
