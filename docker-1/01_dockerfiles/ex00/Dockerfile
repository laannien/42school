FROM alpine

MAINTAINER uheirloo

RUN apk update && \
    apk upgrade && \
    apk add vim

ENTRYPOINT vim

# docker build -t ex00 .
# docker run --rm -it --name vim ex00