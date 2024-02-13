/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
#include <stdint.h>
#pragma once

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name")));
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level")));
