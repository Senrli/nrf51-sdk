# nrf51-sdk
Compiler repo for the nRF51 MCU

The toolchains include the nRF5 SDK `12.3.0-d7731ad`, which contains the source code for the nRF51 MCU. It contains the `GCC-ARM-none-eabi-10.3-2021.10-mac` toolchain, which is the compiler toolchain.

This repo is meant to be included as a submodule to the main repo of the nRF51 project, so that it could be easily referenced.

Make sure to change `GNU_INSTALL_ROOT` field to the respective ones in <SDK>/components/toolchain/gcc/Makefile.posix