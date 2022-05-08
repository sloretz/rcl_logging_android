// Copyright 2022 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <android/log.h>

#include <rcl_logging_interface/rcl_logging_interface.h>
#include <rcutils/allocator.h>
#include <rcutils/logging.h>

// Map rcutils severity to Android priority
int severity_to_priority(int severity)
{
  if (severity <= RCUTILS_LOG_SEVERITY_DEBUG) {
    return ANDROID_LOG_DEBUG;
  } else if (severity <= RCUTILS_LOG_SEVERITY_INFO) {
    return ANDROID_LOG_INFO;
  } else if (severity <= RCUTILS_LOG_SEVERITY_WARN) {
    return ANDROID_LOG_WARN;
  } else if (severity <= RCUTILS_LOG_SEVERITY_ERROR) {
    return ANDROID_LOG_ERROR;
  }
  return ANDROID_LOG_FATAL;
}

rcl_logging_ret_t rcl_logging_external_initialize(
  const char * config, rcutils_allocator_t allocator)
{
  (void)config;
  (void)allocator;
  return RCL_LOGGING_RET_OK;
}

rcl_logging_ret_t rcl_logging_external_shutdown()
{
  return RCL_LOGGING_RET_OK;
}

void rcl_logging_external_log(int severity, const char * name, const char * msg)
{
  __android_log_write(severity_to_priority(severity), name, msg);
}

rcl_logging_ret_t rcl_logging_external_set_logger_level(const char * name, int level)
{
  (void)name;
  (void)level;
  // TODO(sloretz) use rcutils logging for per-name controls on severity
  return RCL_LOGGING_RET_OK;
  // Don't set this because it's process wide ...
  // __android_log_set_minimum_priority(severity_to_priority(level));
}
