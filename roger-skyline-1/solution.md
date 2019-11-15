How to do project "roger-skyline-1'

I. VM Part
You have to run a Virtual Machine (VM) with the Linux OS of your choice (Debian for me) in the hypervisor of your choice (VirtualBox).

- Create VM
- Choose disk size 8000000000B (Debian 1GB = 1000000000B). For some peers this is necessary.
- When you do disk partition, you must make at least one disk of 4.2 GB. But if you use this size then during system running about 0,4 GB will be 'eaten' by automatical reservation for root user. Some peers are too meticulous so for them you can use partition fo 4,59 GB. In that case during **dm -f** command this disk will be seen as 4.2 GB.
