# ar_to_distance
<a name="readme-top"></a>

[JP](README.md) | [EN](README_en.md)

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![License][license-shield]][license-url]


<!-- 目次 -->
<details>
  <summary>目次</summary>
  <ol>
    <li>
      <a href="#概要">概要</a>
    </li>
    <li>
      <a href="#セットアップ">セットアップ</a>
      <ul>
        <li><a href="#環境条件">環境条件</a></li>
        <li><a href="#インストール方法">インストール方法</a></li>
      </ul>
    </li>
    <li><a href="#実行・操作方法">実行・操作方法</a></li>
    <li><a href="#マイルストーン">マイルストーン</a></li>
    <li><a href="#変更履歴">変更履歴</a></li>
    <li><a href="#参考文献">参考文献</a></li>
  </ol>
</details>


<!-- レポジトリの概要 -->
## 概要

- ARタグを読み取り距離を算出するパッケージ
- ARタグからcamera基準のTFを送信します．

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- セットアップ -->
## セットアップ

ここで，本レポジトリのセットアップ方法について説明します．

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- 環境条件 -->
### 環境条件

まず，以下の環境を整えてから，次のインストール段階に進んでください．

| System | Version |
| --- | --- |
| Ubuntu | 20.04 (Focal Fossa) |
| ROS    | Noetic Ninjemys |
| OpenCV | 4.9.0 (動作確認済) |

> [!NOTE]
> UbuntuやROSのインストール方法に関しては，[SOBITS Manual](https://github.com/TeamSOBITS/sobits_manual#%E9%96%8B%E7%99%BA%E7%92%B0%E5%A2%83%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6)に参照してください．

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- インストール方法 -->
## インストール方法

1. ROSのsrcフォルダに移動します．
  ```bash
  $ roscd
  # もしくは，"cd ~/catkin_ws/"へ移動．
  $ cd src/
  ```

2. 本レポジトリをcloneします．
  ```bash
  $ git clone https://github.com/TeamSOBITS/ar_track_alvar
  ```

3. レポジトリの中へ移動します．
  ```bash
  $ cd ar_track_alvar/
  ```

4. パッケージをコンパイルします．
  ```bash
  $ roscd
  # もしくは，"cd ~/catkin_ws/"へ移動．
  $ catkin_make
  ```

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- 実行・操作方法 -->
## 実行・操作方法

1. ARタグの検出のために用いるカメラを起動します．

2. 使用されるカメラに合わせて[ar_detect.launch](ar_track_alvar/launch/ar_detect.launch)を設定します．
  ```xml
  <!-- Real Marker size in cm -->
  <arg name="marker_size"          default="5.4" />
  <!-- Marker detection error in cm -->
  <arg name="max_new_marker_error" default="0.08" />
  <!-- Marker tracking error in cm -->
  <arg name="max_track_error"      default="0.2" />

  <!-- Camera image topic -->
  <arg name="cam_image_topic" default="/rgb/image_raw" />
  <!-- Camera info topic -->
  <arg name="cam_info_topic"  default="/rgb/camera_info" />
  <!-- Camera link -->
  <arg name="output_frame"    default="/azure_camera_base" />
  ```

3. [ar_detect.launch](ar_track_alvar/launch/ar_detect.launch)というlaunchファイルを実行します．
  ```bash
  $ roslaunch ar_track_alvar ar_detect.launch
  ```

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- マイルストーン -->
## マイルストーン

- [x] OSS
    - [x] ドキュメンテーションの充実
    - [x] コーディングスタイルの統一

現時点のバッグや新規機能の依頼を確認するために[Issueページ][issues-url] をご覧ください．

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- 変更履歴 -->
## 変更履歴

変更履歴は[CHANGELOG.rst](CHANGELOG.rst)を参照してください．

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>


<!-- 参考文献 -->
## 参考文献

* [ar_track_alvar (ROS.org)](http://wiki.ros.org/ar_track_alvar)

<p align="right">(<a href="#readme-top">上に戻る</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/TeamSOBITS/ar_track_alvar.svg?style=for-the-badge
[contributors-url]: https://github.com/TeamSOBITS/ar_track_alvar/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/TeamSOBITS/ar_track_alvar.svg?style=for-the-badge
[forks-url]: https://github.com/TeamSOBITS/ar_track_alvar/network/members
[stars-shield]: https://img.shields.io/github/stars/TeamSOBITS/ar_track_alvar.svg?style=for-the-badge
[stars-url]: https://github.com/TeamSOBITS/ar_track_alvar/stargazers
[issues-shield]: https://img.shields.io/github/issues/TeamSOBITS/ar_track_alvar.svg?style=for-the-badge
[issues-url]: https://github.com/TeamSOBITS/ar_track_alvar/issues
[license-shield]: https://img.shields.io/github/license/TeamSOBITS/ar_track_alvar.svg?style=for-the-badge
[license-url]: LICENSE
