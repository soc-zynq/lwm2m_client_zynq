# lwm2m

## Introduction 
LwM2M (Lightweight Machine to Machine) in the context of C++. LwM2M is a protocol designed for managing and communicating with resource-constrained devices, often in IoT (Internet of Things) scenarios. C++ is a popular language for embedded systems and IoT development due to its performance, control over hardware, and ability to write efficient code.

### LwM2M with C++:

What is LwM2M?
OMA SpecWorks Standard: LwM2M is standardized by OMA SpecWorks (formerly Open Mobile Alliance). It's an open and widely adopted protocol.

Designed for IoT: Specifically created for managing devices with limited resources (memory, processing power, battery).

## Client-Server Architecture: LwM2M operates on a client-server model.

### LwM2M Client: Runs on the IoT device. It's responsible for:

 * Registration: Identifying itself to the LwM2M Server.

* Resource Management: Exposing device data and functionalities as "Resources" organized into "Objects."

* Communication: Interacting with the LwM2M Server using CoAP (Constrained Application Protocol) over UDP or SMS, and optionally using DTLS for security.

* Operations: Responding to requests from the server (Read, Write, Execute, Observe).

###  LwM2M Server: A management platform that:
* Registers and Manages Clients: Keeps track of connected devices.
* Monitors Resources: Retrieves data from devices.
* Configures Devices: Sends commands to devices to change settings or trigger actions.
* Provides Device Management Functionality: Firmware updates, device diagnostics, etc.

Key Features:
* Resource Model: Data and functionalities are modeled as Resources within Objects, making it structured and easy to manage.
* CoAP Protocol: Uses CoAP, a lightweight protocol similar to HTTP but optimized for constrained environments.
* DTLS Security: Supports DTLS (Datagram Transport Layer Security) for secure communication.
* Bootstrap: Allows for simplified device onboarding and configuration.
* Observe/Notify: Enables efficient data reporting when resource values change.
* Device Management Operations: Supports firmware updates, factory resets, and more.

## Build
To build the project, run the following commands:
```sh
mkdir build
cd build
cmake ..
make
```

## Run
To run the project, execute the following command:
```sh
./lwm2m_client_zynq
```

## Test
To run the tests, execute the following command:
```sh
ctest
```
