FROM debian

MAINTAINER uheirloo

ENV TS3SERVER_LICENSE=accept

EXPOSE 9987/udp 10011 30033

WORKDIR /home/teamspeak

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install wget bzip2 -y && \
    wget https://files.teamspeak-services.com/releases/server/3.11.0/teamspeak3-server_linux_amd64-3.11.0.tar.bz2 && \
    tar -xjf teamspeak3-server_linux_amd64-3.11.0.tar.bz2

WORKDIR /home/teamspeak/teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh 

# docker build -t ex01 .
# docker run --rm --name teamspeak -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01