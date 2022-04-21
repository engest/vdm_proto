# Project Description
https://github.com/engest/vdm_proto
## Purpose
The purpose of this project is to provide a basic SystemC/TLM2 LT model for educational purposes.

## The Design
### Virtual Device Model Prototype
The Virtual Device Model Prototype, or VDM Proto, is the model of the design we are focussed on. It is the device under development...the device under test (DUT.)

## The Testbench
The testbench simply instantiates the VDM Proto device as well as the TLMDriver module, which is described below.

### TLM Driver Module
This module is the secondary point of focus as it will have a lot of action code it in to stimulate the VDM Proto device by sending READ and WRITE transactions to it. 