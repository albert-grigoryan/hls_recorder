FROM ubuntu:16.04
RUN apt-get update && \
    apt-get install -y vim git build-essential cmake pkg-config \
    libcpprest-dev libboost-all-dev libopencv-dev ffmpeg && \
    cd /tmp && git clone https://github.com/meltwater/served.git && cd served/ && \
    mkdir build && cd build && cmake .. && make && make install
WORKDIR /src
COPY CMakeLists.txt src ./
RUN mkdir build && cd build && cmake .. && make
EXPOSE 80
ENV LD_LIBRARY_PATH=/usr/local/lib
CMD build/hls_recorder
