FROM ubuntu:22.04

# # Get rid of default ubuntu user that occupies uid 1000, this clears way for mapping host user
# RUN userdel -r ubuntu
# Install packages as root
RUN apt-get update
RUN apt-get install -y git \
    vim
# Install bazel
RUN apt install apt-transport-https curl gnupg -y
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
RUN mv bazel-archive-keyring.gpg /usr/share/keyrings
RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt update && apt install -y bazel-8.1.1
RUN git clone https://github.com/protocolbuffers/protobuf.git && \
cd protobuf && git submodule update --init --recursive
RUN bazel-8.1.1 build :protoc :protobuf && cp bazel-8.1.1-bin/protoc /usr/local/bin
# Establish working directory and change docker user to be host, not root
WORKDIR /home/jamespillot
RUN useradd -u 1000 jamespillot && chown -R jamespillot /home/jamespillot
USER jamespillot