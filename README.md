# HLS Recorder

## Overview

HTTP server recording _HTTP Live Video Streames_ to _video/image_ files.

## Features
1. Record HLS stream for 2 seconds - /record?length=2 (NOTE: do not forget to pass the access token in the _HTTP Authorization header_, by default is is equal to _"SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2"_.). E.g.: 
~~~
$ curl -H "Authorization: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2" http://127.0.0.1:81/record?length=2
Captured Record: 64fb01af-214f-499d-bdab-abcf33fdc7d9.avi
~~~
2. Download the record vide file - /record/<file-name>. E.g.:
~~~
curl -H "Authorization: SAskXxSzYuS2nnyvsNQBxKDG25FSyNs2" http://127.0.0.1:81/record/64fb01af-214f-499d-bdab-abcf33fdc7d9.avi > test.avi
~~~

## Installation
1. Clone to your local machine:
~~~
$ git clone https://github.com/albert-grigoryan/hls_recorder.git
~~~
2. Change directory
~~~
$ cd hls_recorder
~~~
2. Download and install _Docker_ from the link: https://www.docker.com/products/docker-desktop
3. Build the container (e.g. with _"hls_recorder:1.0"_ tag)
~~~
$ docker build . -t hls_recorder:1.0
~~~

## Test (tested on _MacOS 10.13_)
To test the installation perform the following steps:
1. Run container:
~~~
$ docker run -p 80:80 -it hls_recorder:1.0
~~~
2. Open the browser and enter the link: http://127.0.0.1/record?length=2

NOTE: _"length"_ parameter specifies the maximum length of the video (in seconds).
