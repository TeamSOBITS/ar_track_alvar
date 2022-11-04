# qr_to_distance

ARコードを読み取り距離を算出するパッケージ

## Install dependent package
```
See [ROS wiki](http://wiki.ros.org/ar_track_alvar) for the users document. 

```
## How to use 
- Azure Kinect Launcher
```
$ roslaunch ar_track_alvar azure_kinect.launch
```
- Xtion Launcher 
```
$ roslaunch ar_track_alvar xtion.launch
```


## Integrate with your tools
ARコードからcamera基準のTFを送信します。
