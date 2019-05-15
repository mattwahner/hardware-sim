FROM ubuntu:18.04
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get install -y cmake flex bison && \
    rm -rf /var/lib/apt/lists/*
RUN mkdir /src
WORKDIR /src
COPY . .
RUN cmake .
RUN make
ENTRYPOINT ["./hardware-sim", "src/sample.hw"]