# ComputerNetworking

![](https://img.shields.io/badge/License-MIT-red.svg)

ComputerNetworking Courses, Lectures, and Programs.

This Repo is almost based on my [college courses](https://github.com/PeterWrighten/OU_Assignment/blob/main/B2/%E6%83%85%E5%A0%B1%E3%83%8D%E3%83%83%E3%83%88%E3%83%AF%E3%83%BC%E3%82%AF%E6%BC%94%E7%BF%92/README.md)(Textbook is [Computer Networks, 5th Edition](https://www.pearson.com/us/higher-education/program/Tanenbaum-Computer-Networks-5th-Edition/PGM270019.html)).

The Lab And Programming are based on [Stanford CS144](https://cs144.github.io/) and [Computer Networking: A Top-down Approach](https://www.ucg.ac.me/skladiste/blog_44233/objava_64433/fajlovi/Computer%20Networking%20_%20A%20Top%20Down%20Approach,%207th,%20converted.pdf).

# Lab

This Repo would almost take some notes and do some prerequisites for labs of CS144 and "Computer Networking: A Top-down Approach", the implementation of Labs would not be included, and I would do it and memo my thoughts about lab proj in following Repos.

## [CS144 Lab](https://github.com/PeterWrighten/CS144_Lab)

## [CNet:A Top-down Appoach Lab](https://github.com/PeterWrighten/CNet_aTop-downapproach_Lab)

# Lecture Note

**[Prerequisites](https://github.com/PeterWrighten/ComputerNetworking/blob/main/prerequisites/README.md)**

## Lecture 1: [How The Internet Works](https://cs144.github.io/handouts/week-1-how-the-internet-works.pdf)

**See the path our packets take**

```$ ping yuba.stanford.edu```
```$ traceroute yuba.stanford.edu```

**Network Diagnostic Tools**

1. traceroute

* ```traceroute -m 255```

The maximum number of hops can be adjusted with the -m flag. If the host you are trying to route to is over 30 hops away, you may need to specify a larger value here. The maximum value you can set is 255.

* ```traceroute google.com 70```

You can adjust the size of the packet that is sent to each hop by giving the integer after the hostname.

* ```traceroute -q1 google.com```

From each host, only "1" packet is tested against for each host.

2. ping

**Summary so far**

Applications send and receive data in packets over an internet that is unreliable.

Packets are forwarded hop-by-hop based on the final destination address.(Dijkstra, Bellman Ford)

>Socket:
A network socket is a software structure within a network node of a computer network that serves as an endpoint for sending and receiving data across the network.

**Reliability from unreliability**

* "Best effort" Delivery

Network service not guaranteed delivery of data.

Fair to all users

Network delay and packet loss all depends on traffic load

* "Best-effort" delivery of datagrams

up to about 1500 bytes.

from one computer to another.

* "Best-effort" means datagram might be:

lost completely;

delivered more than more;

delivered after another datagram that was sent later;

delivered with some bytes changed;

delivered but truncated;

* Reliability

A module behaves reliably when it:

>provides some stated abstraction/interface.

>even in the face of underlying faults.(e.g.packet loss)

>and when it cannot do that, the module signals failure.

> URL -> DNS -> IP Address


**Reliability from unreliable Internet**

1. Timeout
2. ACK, 3-way handshake
3. ARQ

### Review

|Layer|PDU|
|:--:|:--:|
|Physics | Bit  |
|Datalink   | Frame  |
|Network   | Datagram  |
|Transport  | Segment  |
|Application   | Message  |
