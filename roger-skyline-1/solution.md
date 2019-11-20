How to do project "roger-skyline-1'

I. VM Part
You have to run a Virtual Machine (VM) with the Linux OS of your choice (Debian for me) in the hypervisor of your choice (VirtualBox).

- Create VM
- Choose disk size 8000000000B (Debian 1GB = 1000000000B). For some peers this is necessary.
- When you do disk partition, you must make at least one disk of 4.2 GB. But if you use this size then during system running about 0,4 GB will be 'eaten' by automatical reservation for root user. Some peers are too meticulous so for them you can use partition fo 4,59 GB. In that case during **dm -f** command this disk will be seen as 4.2 GB.
For the 4.2GB disk use primery option. The second, logical partition (about 3GB in my case) - for /home. The last partition is for swap.
Install SSH server and standart utilities.
- Install all nesessary packages
**apt install vim sudo ufw portsentry nginx fail2ban**

II. Network and Security Part
For the network on your VM, here are the steps to achieve:
• You must create a non-root user to connect to the machine and work.
• Use sudo, with this user, to be able to perform operation requiring special rights.

You can create user during system installation. After installation login as root and give your user sudo rights:
**sudo adduser user sudo**

• We don’t want you to use the DHCP service of your machine. You’ve got to configure it to have a static IP and a Netmask in \30.

Add second Host-only adapter for VM (VM should be off during this time).
Change */etc/network/interfaces* file, add next settings to the primary network interfaces:

auto enp0s3
iface enp0s3 inet static
	address 10.0.2.1
	netmask 255.255.255.252
	gateway 10.0.2.2

allow-hotplug enp0s8
iface enp0s8 inet static
	address 192.168.29.77
	netmask 255.255.255.252

Restart network service:
**sudo service networking restart**

• You have to change the default port of the SSH service by the one of your choice. SSH access HAS TO be done with publickeys. SSH root access SHOULD NOT be allowed directly, but with a user who can be root.

For changing default port change file */etc/ssh/sshd_config*
- uncommit line Port 22
- change port to 50000
- uncommit line with PermitRootLogin and write **no** instead of default setting (it doesn't allow root login)

On your MAC run command to create SSH keys (*id_rsa* is a secure key, that you keep on your MAC, and *id_rsa.pub* is a public key, that shoud be copied and stored at your VM):
**ssh-keygen -t rsa**

Send public key to VM (it will be stored at *~/.ssh/authorized_keys* on your VM):
**ssh-copy-id -i ~/.ssh/id_rsa.pub user@*you mac's IP address*  -p *mac port that forwards to the VM's SSH port***



• You have to set the rules of your firewall on your server only with the services used
outside the VM.
• You have to set a DOS (Denial Of Service Attack) protection on your open ports
of your VM.
• You have to set a protection against scans on your VM’s open ports.
• Stop the services you don’t need for this project.
• Create a script that updates all the sources of package, then your packages and
which logs the whole in a file named /var/log/update_script.log. Create a scheduled
task for this script once a week at 4AM and every time the machine reboots.
• Make a script to monitor changes of the /etc/crontab file and sends an email to
root if it has been modified. Create a scheduled script task every day at midnight.