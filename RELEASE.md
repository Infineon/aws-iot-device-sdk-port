# AWS IoT Device SDK Port Library

## What's Included?

See [README.md](./README.md) for details.

## Known Issues
| Problem | Workaround |
| ------- | ---------- |
| IAR 9.40.2 toolchain throws build errors on Debug mode, if application explicitly includes iar_dlmalloc.h file | Add '--advanced_heap' to LDFLAGS in application Makefile. |

## Changelog

### v2.6.0
- Added support to create TLS identity without private key.

### v2.5.0
- Added support for CYW955913EVK-01 kit

### v2.4.1
- Added changes to eliminate use of HAL TRNG APIs

### v2.4.0
- Supports Mbed TLS version 3.4.0
- Added support for CY8CEVAL-062S2-CYW43022CUB kit

### v2.3.0
- Minor bug fixes.
- Added support for KIT_XMC72_EVK_MUR_43439M2 kit

### v2.2.4
- Minor Documentation Update.

### v2.2.3
- Made FreeRTOS specific code generic.
- Changes to rename COMPONENT_43907 to COMPONENT_4390X

### v2.2.2
- Added API to verify certificate using signer certificate.
- Added Flash erase API and Updated Flash read, seek APIs to handle HOTA updates and certificate updates.
- Added support for CM0P core.
- Minor Documentation Updates.

### v2.2.1
- Renamed OTA and socket port layer c files.
- Moved ota_config.h to *configs* folder.

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
| ModusToolbox&trade; Software Environment                  | 3.2     |
| ModusToolbox&trade; Device Configurator                   | 4.20    |
| GCC Compiler                                              | 11.3.1  |
| IAR Compiler                                              | 9.40.2  |
| Arm Compiler 6                                            | 6.16    |
