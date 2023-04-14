# Title

## Introduction

The following guide is intended to assist in setting up several components that work together to ensure a Trusted Execution Enviroment (*TEE*) in a cloud provider. In particular we have used Gramine in conjunction with Intel Software Guard Extension (*SGX*) and a Data Center Attestation Primitives (*DCAP*) infrastructure to obtain the intended result.

- Intel SGX processors offer hardware-based memory encryption that isolates specific application code and data in memory. Intel SGXs allow allocate private areas of memory, called enclaves, designed to be protected from processes running at higher levels of privilege (such as the operating system).
- Gramine is a library Operating System that, among other things, has a special use case of SGX integration. More specifically it allows to run unmodified applications inside SGX.
- DCAP

### Work environment

- Operating system: 
- Linux kernel version: 
- CPUs: 

### Prerequisites


## Setup SGX components

### Build and install SDK

### Build and install PSW

## Setup Gramine

## Setup DCAP infrastructure
