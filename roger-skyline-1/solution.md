How to do project "roger-skyline-1'

**I. VM Part**
You have to run a Virtual Machine (VM) with the Linux OS of your choice (Debian for me) in the hypervisor of your choice (VirtualBox).

- Create VM
- Choose disk size 8000000000B (Debian 1GB = 1000000000B). For some peers this is necessary.
- When you do disk partition, you must make at least one disk of 4.2 GB. But if you use this size then during system running about 0,4 GB will be 'eaten' by automatical reservation for root user. Some peers are too meticulous so for them you can use partition fo 4,59 GB. In that case during **dm -f** command this disk will be seen as 4.2 GB.
For the 4.2GB disk use primery option. The second, logical partition (about 3GB in my case) - for /home. The last partition is for swap.
Install SSH server and standart utilities.
- Install all nesessary packages
**apt install vim sudo ufw portsentry nginx mailutils fail2ban -y**

**II. Network and Security Part**
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
- uncomment line Port 22
- change port to 50000
- uncomment line with PermitRootLogin and write **no** instead of default setting (it doesn't allow root login)

On your MAC run command to create SSH keys (*id_rsa* is a secure key, that you keep on your MAC, and *id_rsa.pub* is a public key, that shoud be copied and stored at your VM):
**ssh-keygen -t rsa**

Send public key to VM (it will be stored at *~/.ssh/authorized_keys* on your VM):
**ssh-copy-id -i ~/.ssh/id_rsa.pub user@*you mac's IP address*  -p *mac port that forwards to the VM's SSH port***

Change file */etc/ssh/sshd_config*
- uncomment line with PasswordAuthentication and write **no** instead of default setting

• You have to set the rules of your firewall on your server only with the services used outside the VM.

To disable IPv6 change file */etc/default/ufw*, change line 7 to  **IPv6=no**

Before enabeling ufw you have to open port for SSH connection:
**sudo ufw allow 50000**

Then we will need ports for HTTP and HTTPS:
**sudo ufw allow 80**
**sudo ufw allow 443**

Now you can enable ufw and check its status:
**sudo ufw enable**
**sudo ufw status verbose**

It should show you next status:
Status: active
Logging: on (low)
Default: deny (incoming), allow (outgoing), disabled (routed)
New profiles: skip

To                         Action      From
--                         ------      ----
50000                      ALLOW IN    Anywhere
443                        ALLOW IN    Anywhere
80                         ALLOW IN    Anywhere

If Default's lines are different, you should set them right and restart ufw:
**sudo ufw default deny incoming**
**sudo ufw default allow outgoing**
**sudo ufw logging low**

• You have to set a DOS (Denial Of Service Attack) protection on your open ports
of your VM.

Create a file */etc/fail2ban/jail.local* and add to it: 
[nginx-dos]
# Any IP requesting more than 240 pages in 60 seconds, 
# or 4 p/s average, is suspicious. Block it for two full days.
enabled = true
port = http
filter = nginx-dos
logpath = /var/log/nginx/access.log
findtime = 60
bantime = 172800
maxretry = 240

Create a file */etc/fail2ban/filter.d/nginx-dos.conf* and add to it:
[Definition]
# Option: failregex
# Notes.: Regexp to catch a generic call from an IP address.
# Values: TEXT
failregex = ^<HOST> -.*"(GET|POST).*HTTP.*"$
# Option: ignoreregex
# Notes.: regex to ignore. If this regex matches, the line is ignored.
# Values: TEXT
#
ignoreregex =

Then restart fail2ban service, check its jail's status and status of newly created jail:
*sudo service fail2ban restart*
*sudo fail2ban-client status*
*sudo fail2ban-client status nginx-dos*

You can check how it works with scripts like Slowloris, but take into account that it will take some time to ban IP.
To unban blocked IP:
**sudo fail2ban-client set *name of jail* * unbanip *banned IP address***

• You have to set a protection against scans on your VM’s open ports.

To do this you should use portsentry

At first you have to change lines at file */etc/default/portsentry* to the next one:
TCP_MODE="atcp"
UDP_MODE="audp"

Then change lines in file */etc/portsentry/portsentry.conf* tp next one:
TCP_MODE="atcp"
UDP_MODE="audp"

Restart portsentry and check its status:
**sudo systemctl restart portsentry**
**sudo systemctl status portsentry**

You can check how it works with nmap from another VM. To unban blocked IP you should delete lines with used IP from */etc/hosts.deny* and from files from directory */var/lib/portsentry/* and then reboot VM.

• Stop the services you don’t need for this project.




• Create a script that updates all the sources of package, then your packages and which logs the whole in a file named /var/log/update_script.log. Create a scheduled task for this script once a week at 4AM and every time the machine reboots.

To make scheduled scripts use cron service.
Create script */etc/cron.d/update.sh*:
#!/bin/sh
LOG="/var/log/update_script.log"
sudo apt update -y | tail -n1 >> $LOG
sudo apt upgrade -y | tail -n1 >> $LOG
exit

Give to this file permission for execution:
**sudo chmod +x /etc/cron.d/update.sh**

Create a file where logs will be saved */var/log/update_script.log* and give to it read and write permissions: 
**sudo chmod 666 /var/log/update_script.log**

Make changes at file */etc/crontab* to create schedule:
@reboot root /etc/cron.d/update.sh
0 4 * * 2 root /etc/cron.d/update.sh

The last line runs script every Tuesday at 04:00 AM.

You can write your script directly at */etc/crontab* where the path to script is written, but it looks neater to write in special file as I did.

Don't forget to restart cron after all changes:
**sudo systemctl restart cron**
**sudo systemctl status cron**

• Make a script to monitor changes of the /etc/crontab file and sends an email to root if it has been modified. Create a scheduled script task every day at midnight.

As we've done it at the previous task, create script */etc/cron.d/monitor-changes.sh*:
#!/bin/sh
MSG="File /etc/crontab has been modified!" 
SUBJECT="Monitor changes crontab"
TO="root@localhost"
HASH="/etc/cron.d/hash.txt"
FILE="/etc/crontab"
test -f $HASH || sudo touch $HASH
CRON_HASH=$(sudo md5sum $FILE)
if [ "$(cat $HASH)" != "$CRON_HASH" ]; then
    echo $CRON_HASH > $HASH
	echo $MSG | mail -s "$SUBJECT" $TO
fi;
exit

Add this line to */etc/crontab*:
0 0 * * * root /etc/cron.d/monitor_changes.sh

Don't forget to restart cron after all changes:
**sudo systemctl restart cron**
**sudo systemctl status cron**