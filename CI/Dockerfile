FROM ubuntu:bionic
ENV DEBIAN_FRONTEND=noninteractive

# get the basic stuff
RUN apt-get update && apt-get install -y \
	build-essential \
	git \
	autoconf \
	libtool \
	pkg-config \
	gnupg \
	apt-transport-https \
	ca-certificates \
	software-properties-common \
	wget \
	python \
	perl \
	cpanminus \
	gzip \
	expect \
	unzip

# kitware repo for latest cmake
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | apt-key add -

# repo for g++-9
RUN apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'
RUN add-apt-repository ppa:ubuntu-toolchain-r/test

RUN apt-get update && apt-get install -y \
	cmake \
	g++-9

# set gcc defaults
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 60
RUN update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-9 60
RUN update-alternatives --install /usr/bin/gcov-tool gcov-tool /usr/bin/gcov-tool-9 60

# install lcov and dependencies
RUN apt-get install zlib1g-dev
RUN cpanm install JSON
RUN cpanm install 'PerlIO::gzip'


# build cppcheck
RUN git clone https://github.com/danmar/cppcheck
# silence output so it doesn't get picked up by static analyzers
RUN sh -c "cd cppcheck && mkdir build && cd build && \
	cmake .. -DUSE_MATCHCOMPILER=ON \
	&& make && make install" >/dev/null 2>&1

# build lcov
RUN git clone https://github.com/linux-test-project/lcov.git
RUN sh -c "cd lcov && make install" >/dev/null 2>&1


# install dependencies for the project
RUN apt-get install -y curl libcurl4-gnutls-dev

ENV LD_LIBRARY_PATH=/libs
ENV CPLUS_INCLUDE_PATH=/libs/include
ENV TERM=xterm
