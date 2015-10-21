FROM    ubuntu:latest

ENV   USER scoudert
ENV   HOSTNAME 42born2code

RUN apt-get update &&\
apt-get upgrade -y &&\
apt-get install -y openssh-server && \
sed -i 's/Port 22/Port 42/g' /etc/ssh/sshd_config && \
sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/g' /etc/ssh/sshd_config && \
useradd -s "/bin/bash" $USER && \
mkdir -p /home/$USER/.ssh

ADD id_rsa.pub /home/$USER/.ssh/authorized_keys

EXPOSE  42

CMD    service ssh start & /bin/bash
