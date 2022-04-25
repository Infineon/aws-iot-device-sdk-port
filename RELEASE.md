# AWS IoT Device SDK Port Library

## What's Included?

See [README.md](./README.md) for details.

## Known Issues

- None.

## Changelog
### v2.2.1
- Renamed OTA and socket port layer c files.

### v2.2.0
- Added OS and PAL functional interface routines for AWS OTA.

### v2.1.0
- Added support for CYW954907AEVAL1F and CYW943907AEVAL1F kits.

### v2.0.0

- Added support to register socket data receive callback.

- Updated [Amazon's AWS-IoT-Device-SDK-Embedded-C Library](https://github.com/aws/aws-iot-device-sdk-embedded-C/tree/202103.00) version.

### v1.0.1

- Added support to establish secure connection with or without RootCA certificate.

### v1.0.0

- Initial release.
- Port layer implementation for [Amazon's AWS-IoT-Device-SDK-Embedded-C Library](https://github.com/aws/aws-iot-device-sdk-embedded-C/tree/202011.00).

### Supported Software and Tools

This version of the library was validated for compatibility with the following software and tools:

| Software and Tools                                        | Version |
| :---                                                      | :----:  |
| ModusToolbox&trade; Software Environment                  | 2.4     |
| - ModusToolbox&trade; Device Configurator                 | 3.10    |
| - ModusToolbox&trade; CapSense Configurator / Tuner tools | 4.0     |
| PSoC 6 Peripheral Driver Library (PDL)                    | 2.3.0   |
| GCC Compiler                                              | 10.3.1  |
| IAR Compiler                                              | 8.32    |
| Arm Compiler 6                                            | 6.14    |
