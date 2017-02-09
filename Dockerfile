FROM andreroquem/clang-build

MAINTAINER André Roque Matheus <amatheus@mac.com>

RUN mkdir /app

COPY . /app

RUN mkdir /app/build

RUN cd /app/build; cmake -DBUILD_TEST=1 ..; make; make check