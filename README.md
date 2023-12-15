[![Build](https://github.com/riley0122/numworks_template_cpp/actions/workflows/main.yml/badge.svg)](https://github.com/riley0122/numworks_template_cpp/actions/workflows/main.yml)
# C++ Numworks Development template

This is a template to start developing for the [Numworks](https://www.numworks.com/) graphing calculator.

This template was reverse-engineered from the [Numworks C++ sample project](https://github.com/numworks/epsilon-sample-app-cpp).

## Building

To build the app, you need to have node.js installed and GCC, also you will need the embedded ARM toolchain and the nwlink nodejs package. You might also need other dependencies, In case you need another dependency: please [open an issue](https://github.com/riley0122/numworks_template_cpp/issues/new).

You can build the app by running
`
make build
`.

And you can run it on a calculator connected to your computer with
`
make run
`.
