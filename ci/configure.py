#! /usr/bin/env python3

from os import environ as env
from subprocess import check_call


def define(key: str, value: str):
    return ["-D", f"{key}={value}"]


def define_env(name: str):
    return define(name, env[name]) if name in env else []


if __name__ == "__main__":
    command = ["cmake"]
    command += ["-S", "."]
    command += ["-B", "build"]
    command += ["-G", "Ninja"]
    command += define_env("CMAKE_BUILD_TYPE")
    command += define_env("CMAKE_TOOLCHAIN_FILE")
    command += define("CMAKE_SUPPRESS_REGENERATION", "ON")
    command += define("CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY", "ON")
    command += define_env("VCPKG_TARGET_TRIPLET")

    check_call(command)
