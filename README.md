# HLS recorder

## Overview

HTTP server recording _HTTP Live Video Streames_ to _video/image_ files.

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

NOTE: The _"length"_ parameter specifies the maximum length of the video (in seconds).
