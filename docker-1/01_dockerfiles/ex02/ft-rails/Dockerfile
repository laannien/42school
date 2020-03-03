FROM        ruby

MAINTAINER  uheirloo

EXPOSE 3000
EXPOSE 443
EXPOSE 80

RUN         gem install rails bundler:2.1.4 &&\
            gem install rails &&\
            apt-get update -qq && apt-get upgrade -qq &&\
            apt-get install -y nodejs
            
RUN         mkdir /opt/app &&\
            cp /usr/local/bundle/bin/rails /opt/app/rails

WORKDIR     /opt/app/

RUN         curl -o- -L https://yarnpkg.com/install.sh | bash
RUN         bash &&\
            rails new .

ENTRYPOINT  bash


# How to build
# docker build -t ft-rails:on-build .