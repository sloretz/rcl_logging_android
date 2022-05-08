# rcl_logging_android
This is a ROS 2 logger backend for android that uses [`__android_log_write`](https://developer.android.com/ndk/reference/group/logging#group___logging_1ga32a7173b092ec978b50490bd12ee523b)

This allows log messages to be viewed using `adb logcat`.

`rcl` needs to be compiled from source to change the logging implementation.
Change it by passing the CMake argument `-DRCL_LOGGING_INTERFACE=rcl_logging_android` when configuring CMake for `rcl`.
