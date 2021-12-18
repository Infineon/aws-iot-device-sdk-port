# AWS IoT Device SDK Port Library

This library is a port layer implementation for the Cypress MQTT and HTTP Client libraries to work with the AWS-IoT-Device-SDK-Embedded-C library on Cypress PSoC® 6 MCU connectivity-enabled platforms. These library APIs are not expected to be called by application directly. See the MQTT and HTTP Client library documentation for more details.

## OTA Support

This aws-iot-device-sdk-port layer implementation also supports PAL APIs required by AWS-IoT-Device-SDK-Embedded-C OTA.
By default, OTA support is disabled. To enable OTA support follow below steps.

1. Add the `CY_OTA_FLASH_SUPPORT` macro in the application Makefile. The Makefile entry should look like as follows:
    ```
    DEFINES+=CY_OTA_FLASH_SUPPORT
    ```

2. If using *.lib* files, create a *.lib* files for anycloud-ota and serial-flash as follows and add *.lib* file along with other dependent library *.lib* files:

   *anycloud-ota.lib*: http://git-ore.aus.cypress.com/repo-staging/anycloud-ota#release-v4.1.0 <br>
   *serial-flash.lib*: https://github.com/cypresssemiconductorco/serial-flash#latest-v1.X

3. If using *.mtb* files, create a *.mtb* files for anycloud-ota and serial-flash as follows and add *.mtb* file along with other dependent library *.mtb* files:

   *anycloud-ota.mtb*: http://git-ore.aus.cypress.com/repo-staging/anycloud-ota#release-v4.1.0#$$ASSET_REPO$$/anycloud-ota/ <br>
   *serial-flash.mtb*: https://github.com/cypresssemiconductorco/serial-flash#latest-v1.X#$$ASSET_REPO$$/serial-flash/

4. Execute the `make getlibs` command.

5. The reference file *./include/ota_config.h* that is bundled with this library provides the default configurations required for the [AWS IoT device SDK](https://github.com/aws/aws-iot-device-sdk-embedded-C/tree/202103.00) OTA library. Copy the reference file *./include/ota_config.h* to application root folder, tune the OTA configuaration parameter as required by application and add OTA signing certificate to macro `AWS_IOT_OTA_SIGNING_CERT`.

6. Add the anycloud-ota library configs include path. This is required to compile the aws-iot-device-sdk-port library with OTA support. The Makefile entry should look like as follows:
   ```
   INCLUDES+=libs/anycloud-ota/configs/
   ```

7. Build application using `make build` command.


## Additional Information

- [AWS IoT Device SDK Port Library RELEASE.md](./RELEASE.md)

- [AWS IoT Device SDK Port Library Version](./version.xml)

- [AWS IoT Device SDK Port Library API Documentation](https://cypresssemiconductorco.github.io/aws-iot-device-sdk-port/api_reference_manual/html/index.html)

- [Amazon's AWS-IoT-Device-SDK-Embedded-C Library](https://github.com/aws/aws-iot-device-sdk-embedded-C/tree/202103.00)

- [MQTT Client Library API Documentation](https://cypresssemiconductorco.github.io/mqtt/api_reference_manual/html/index.html)

- [HTTP Client Library API Documentation](https://cypresssemiconductorco.github.io/http-client/api_reference_manual/html/index.html)

- [Connectivity Utilities API documentation - for cy-log details](https://cypresssemiconductorco.github.io/connectivity-utilities/api_reference_manual/html/group__logging__utils.html)

- [ModusToolbox&trade; Software Environment, Quick Start Guide, Documentation, and Videos](https://www.cypress.com/products/modustoolbox-software-environment)

- [ModusToolbox&trade; code examples](https://github.com/Infineon?q=mtb-example-anycloud%20NOT%20Deprecated)
