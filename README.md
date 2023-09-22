# Demo using [wrapped Tuya IoT Core SDK](https://github.com/gcopoix/tuya-iot-core-sdk)

This project is simply a copy of the Tuya [data_model_basic_demo.c](https://github.com/tuya/tuya-iot-core-sdk/tree/main/examples/data_model_basic_demo) - but cross compilable. \
The [wrapped Tuya IoT Core SDK](https://github.com/gcopoix/tuya-iot-core-sdk) is added to this project as git submodule and included by cmake using [add_subdirectory()](CMakeLists.txt#L38) so this SDK can be conveniently be used as library for this demo and compiled

- as native executable (easy to debug for development purposes)
- as cross compiled executable with [dummy platform port](src/platform/dummy). \
  A [sample toolchain file](cmake/gcc-arm-none-eabi.cmake) has been added as example.


# Development environment
This project offers a [workspace file](.vscode/tuya-iot-core-example.code-workspace) for [Visual Studio Code](https://code.visualstudio.com) with pre-configured

- plugin recommendations
   - C/CPP Syntax highlighting
   - cmake support
- project build/run settings
- debug environment

The cmake is configured with a [sample toolchain file](cmake/gcc-arm-none-eabi.cmake), so always the x64 and arm targets are build. \
If you want to disable the additional cross build, simply remove or disable the ["CMAKE_TOOLCHAIN_FILE" parameter](.vscode/tuya-iot-core-example.code-workspace#L40)

# ToDo for own project
- follow the [steps](https://developer.tuya.com/en/docs/iot/link-sdk?id=Kaiuyfihfgkr5#title-3-Step%202%3A%20Configure%20device%20information) to create an own Tuya account and get your own set of credentials \
  (skip Step 1 as the SDK is already part of this sample)
- port to embedded target and implement [platform_port](src/platform) for a real target
- happy developing
