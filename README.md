# Demo using [wrapped Tuya IoT Core SDK](https://github.com/gcopoix/tuya-iot-core-sdk)

This demo is simply a copy of [Tuya data_model_basic_demo](https://github.com/tuya/tuya-iot-core-sdk/tree/main/examples/data_model_basic_demo). \
The [wrapped Tuya IoT Core SDK](https://github.com/gcopoix/tuya-iot-core-sdk) is added to this project so this SDK can be used as library for this demo.

It builds
- a native executable (easy to debug for development purposes)
- a cross compiled executable with [dummy platform port](src/platform/dummy). \
  A [sample toolchain file](cmake/gcc-arm-none-eabi.cmake) has been added as example.

# Development environment
This project offers a [workspace file](.vscode/my-tuya-iot-core-sdk.code-workspace) for [Visual Studio Code](https://code.visualstudio.com) with pre-configured

- plugin recommendations
   - C/CPP Syntax highlighting
   - cmake support
- project build/run settings
- debug environment


# ToDo
- create and add own set of credentials
- port to embedded target and implement [platform_port](src/platform) for a real target
- additional data points
