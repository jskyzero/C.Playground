# Sniff
`jskyzero` `2017/11/26`

## Overview

minisniff is a mini sniff that capture package and show some info about the package.

## Install & Run
1. Fitst Install Dependence `sudo apt-get install libpcap0.8-dev`

2. Try to Make it `make`

3. Run as `sudo ./minisniff 2` to capture 2 package

## Question & Answer

1. What library does minisniff use to capture packets? Where in the web can you find more information about this library?
2. Do some research and describe the advantages/disadvantage of using this library? Do not blindly copy and paste material from the web. Try to understand the material you find and write what you understood.
3. Are there any alternative libraries available to capture packets? (Open source only)
4. Explain the purpose of the following functions:
a. pcap_lookupdev
b. pcap_open_live
c. pcap_lookupnet
d. pcap_compile
e. pcap_setfilter
f. pcap_next
g. pcap_loop
h. pcap_dispatch
5. There are five layers in the TCP/IP stack (application, transport, network, link, and physical). Up to what layer can minisniff decode data from the captured
packets? Justify your answer using the code.

## Original Readme

```
		readme file for minisniff
		-------------------------
i don't think i need to tell you this but i'll tell it anyway, minisniff is written for you to experiment with the source code for network security classes CS393/CS682. DO NOT USE this sniffer outside our security testbed in isis lab.

so, this is a sample code for how to start writing a sniffer. i hope this answers most of your questions about how hard/easy it is to capture packets off the wire and how to write a sniffer etc. you need to download and install pcap (packet capture) library on your machine to compile the sniffer. you can download pcap from http://www.tcpdump.org/ once you install the pcap library all you need to do is type 'make' in the directory where you have this README file, so that the files can be compiled. there shouldn't be errors or warnings, if so email me the errors, copy-paste them, don't even attempt to describe the errors on your own words:-) 

if you just want to run the sniffer and see what it does use the compiled 'minisniff' file that comes with this file, then you don't need pcap library, but the file is compiled on Linux (i-386, ELF) so obviously it wont work on other operating systems. you should be able to execute the sniffer by typing './minisniff 20' to capture and display information about 20 packets.

feel free to modify the code and enhance the sniffer as you please. drop me a line if you need any help, but i don't guarantee that i'd be able to help you.
```

## Reference
