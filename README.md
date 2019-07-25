# HLS Recorder

## Overview

HTTP server recording _HTTP Live Video Streams_ to _video/image_ files. Build with CMake and packeged with Docker.

Libraries Used:
- Boost
- OpenCV
- Served

Tools used:
- CMake 
- Docker

## Features
1. Record HLS stream - **/record?length=n** (NOTE: do not forget to pass the access token in the _HTTP Authorization header_, by default is is equal to _"SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2"_.). E.g. for 2 seconds: 
~~~
$ curl -H "Authorization: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2" http://127.0.0.1/record?length=2
Captured Record: 64fb01af-214f-499d-bdab-abcf33fdc7d9.avi
~~~
2. Download the recorded file - **/record/\<file_uuid\>**. E.g. _"64fb01af-214f-499d-bdab-abcf33fdc7d9.avi"_ record:
~~~
curl -H "Authorization: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2" http://127.0.0.1/record/64fb01af-214f-499d-bdab-abcf33fdc7d9.avi > test.avi
~~~
3. Capture frames from HLS stream - **/frames?count=n**. E.g. 3 frames:
~~~
$ curl -H "Authorization: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2" http://127.0.0.1/frames?count=3
Captured Frames: 38437b94-552c-4331-bf14-c256c5f8bde7_0001.jpg 38437b94-552c-4331-bf14-c256c5f8bde7_0002.jpg 38437b94-552c-4331-bf14-c256c5f8bde7_0003.jpg
~~~
4. Download captured frames - **/frames/\<frame_uuid\>**. E.g. "_38437b94-552c-4331-bf14-c256c5f8bde7_0001.jpg_" frame :
~~~
$ curl -H "Authorization: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2" http://127.0.0.1/frames/38437b94-552c-4331-bf14-c256c5f8bde7_0001.jpg > test.jpg
~~~

## Installation
1. Clone to your local machine:
~~~
$ git clone https://github.com/albert-grigoryan/hls_recorder.git
~~~
2. Change directory:
~~~
$ cd hls_recorder
~~~
2. Download and install _Docker_ from the link: https://www.docker.com/products/docker-desktop.
3. Build a Docker container (e.g. with _"hls_recorder:1.0"_ tag):
~~~
$ docker build . -t hls_recorder:1.0
~~~

## Test (tested on _MacOS 10.13_)
To test the installation perform the following steps:
1. Run server from Docker container:
~~~
$ docker run -p 80:80 -it hls_recorder:1.0
~~~
2. Test above mentioned features.

Good Luck!
