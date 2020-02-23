# Get the base Ubuntu image from Docker Hub and update packages.
FROM ubuntu:16.04
RUN apt-get update && apt-get upgrade -y

# Install tools/third-party libraries
RUN apt-get update && apt-get install -y \
    build-essential   \
    pkg-config        \
    cmake             \
    git               \
    libboost-all-dev

# Copy source code
WORKDIR /src
COPY src src
COPY third_party third_party
COPY CMakeLists.txt .

# Build
RUN mkdir build && cd build && cmake -D BUILD_DOCS=OFF .. && make -j`nproc`

ENV LD_LIBRARY_PATH=/usr/local/lib
EXPOSE 80

# Run
CMD build/hls_recorder
