# Stage 1: Build libzmq and cppzmq
FROM ubuntu:latest AS builder

RUN apt-get update -y && \
    apt-get install -y cmake g++ git

WORKDIR /app

RUN git clone https://github.com/zeromq/libzmq.git && \
    cd libzmq && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_COMPILER=g++ .. && \
    make && \
    make install && \
    cd ../..

RUN git clone https://github.com/zeromq/cppzmq.git && \
    cd cppzmq && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_COMPILER=g++ .. && \
    make && \
    make install && \
    cd ../..

# Stage 2: Build the main application
FROM ubuntu:latest

# Install necessary dependencies
RUN apt-get update -y && \
    apt-get install -y cmake g++

WORKDIR /app

# Copy only the necessary files from the first stage
COPY --from=builder /usr/local/ /usr/local/

# Copy the CMakeLists.txt and source code into the container
COPY CMakeLists.txt .
COPY zmq/ zmq/
# COPY other_source_files.cpp .

# Create a build directory and set it as the working directory
RUN mkdir build
WORKDIR /app/build

# Run CMake to configure the project
RUN cmake ..

# Build the project
RUN make

# Set the entry point for the Docker image
CMD ["./rrclient"]
