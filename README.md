# Title

## Introduction

The following guide is intended to assist in setting up several components that work together to ensure a Trusted Execution Enviroment (*TEE*) in a cloud provider. In particular we have used Gramine in conjunction with Intel Software Guard Extension (*SGX*) and a Data Center Attestation Primitives (*DCAP*) infrastructure to obtain the intended result.

- Intel SGX processors offer hardware-based memory encryption that isolates specific application code and data in memory. Intel SGXs allow allocate private areas of memory, called enclaves, designed to be protected from processes running at higher levels of privilege (such as the operating system).
- Gramine is a library Operating System that, among other things, has a special use case of SGX integration. More specifically it allows to run unmodified applications inside SGX.
- DCAP

### Goals

### Work environment

- Operating system: 
- Linux kernel version: 
- CPUs: 

### Prerequisites


## Setup SGX components

All the documentation needed for this section can be found in the following [Github repository](https://github.com/intel/linux-sgx). In order to setup SGX components, you have to:

1. Install the required tools:
```
dnf groupinstall 'Development Tools'
dnf install ocaml ocaml-ocamlbuild wget python3 openssl-devel git cmake perl \
openssl-devel libcurl-devel protobuf-devel cmake rpm-build createrepo yum-utils \
pkgconf boost-devel protobuf-lite-devel systemd-libs
```
1. Create an alternative for the python3 command:
```
alternatives --install /usr/bin/python python /usr/bin/python3 1
alternatives --set python /usr/bin/python3
```
1. Clone the repository for the source code:
```
git clone https://github.com/intel/linux-sgx
cd linux-sgx
```
1. Trigger trigger the script ```download_prebuilt.sh```:
```
make preparation
```
1. Copy the mitigation tools corresponding to current OS distribution from ```external/toolset/{current_distr}``` to ```/usr/local/bin``` and make sure they have execute permission. For example:
```
cp external/toolset/rhel8.6/* /usr/local/bin
which ar as ld objcopy objdump ranlib
```

### Build and install SDK

The easiest way to install the SDK is to build the installer directly:
```
make sdk_install_pkg
```

The generated Intel(R) SGX SDK installer (```sgx_linux_x64_sdk_${version}.bin```) is located under ```linux/installer/bin/```, where ```${version}``` refers to the version number, for example ```linux/installer/bin/sgx_linux_x64_sdk_2.19.100.3.bin```.

To install the SDK:
```
cd linux/installer/bin
./sgx_linux_x64_sdk_${version}.bin --prefix {SDK_INSTALL_PATH_PREFIX}
```

Finally, SDK require some environment variables to compile codes. The following command will run a bash script to setup these environment variables:
```
source ${sgx-sdk-install-path}/environment
```

### Build and install PSW

### Adjust User Group

On any distro with systemd v248 or later, ```/dev/sgx_enclave``` is only accessible by users in the group ```sgx```. The enclave app should be run with a uid in the sgx group:
```
# check systemd version:
systemctl --version

# add sgx group to user if it's 248 or above:
sudo usermod -a -G sgx <user name>
```

## Setup DCAP infrastructure

## Setup Gramine

### Build

### Install
