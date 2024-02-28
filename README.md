# **ar_to_distance**
<a name="readme-top"></a>

[JP](README.md) | [EN](readme_en.md)

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
<!-- [![MIT License][license-shield]][license-url] -->

<!-- 目次 -->
<details>
  <summary>目次</summary>
  <ol>
    <li>
      <a href="#概要">概要</a>
    </li>
    <li>
      <a href="#環境構築">環境構築</a>
      <ul>
        <li><a href="#環境条件">環境条件</a></li>
        <li><a href="#インストール方法">インストール方法</a></li>
      </ul>
    </li>
    <li><a href="#実行・操作方法">実行・操作方法</a></li>
    <li><a href="#マイルストーン">マイルストーン</a></li>
    <li><a href="#変更履歴">変更履歴</a></li>
    <!-- <li><a href="#contributing">Contributing</a></li> -->
    <!-- <li><a href="#license">License</a></li> -->
    <li><a href="#参考文献">参考文献</a></li>
  </ol>
</details>

<!-- レポジトリの概要 -->
## 概要
- ARコードを読み取り距離を算出するパッケージ
- ARコードからcamera基準のTFを送信します．
- ※/ar_track_alvar/makers　にあるARマーカーを使用して検出してください．
<p align="right">(<a href="#readme-top">上に戻る</a>)</p>

<!-- セットアップ -->
## セットアップ
 [ROS wiki](http://wiki.ros.org/ar_track_alvar) を参照してください.

### 環境条件
以下に正常動作環境を示します．
| System  | Version |
| ------------- | ------------- |
| Ubuntu    | 20.04 (Focal Fossa) |
| ROS       | Noetic Ninjemys |

<!-- 実行・操作方法 -->
## 実行・操作方法
<!-- デモの実行方法やスクリーンショットがあるとわかりやすくなるでしょう -->
- Azure Kinect Launcher(Azure Kinectを使用して検出します)
```
$ roslaunch ar_track_alvar azure_kinect.launch
```
※その他のカメラを使用した場合は、トピック名とframe名を変更してください．
- [Topに戻る](#ar_to_distance)

<!-- マイルストーン -->
## マイルストーン
- [ ] OSS
    - [ ] ドキュメンテーションの充実
    - [ ] コーディングスタイルの統一

現時点のバッグや新規機能の依頼を確認するために[Issueページ](https://github.com/ros-perception/ar_track_alvar/issues) をご覧ください．

<p align="right">(<a href="#readme-top">上に</a>)</p>

<!-- 変更履歴 -->
## 変更履歴
  変更履歴はrst.fileを参照してください
<!-- 参考文献 -->
## 参考文献

* []()
* []()
* []()

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
[license-url]: https://github.com/TeamSOBITS/ar_track_alvar/blob/master/LICENSE.txt
