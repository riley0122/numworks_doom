/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
#include "eadk_vars.h"
#include "eadkpp.h"

// Provide the actual definitions
const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "DOOM";
const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;
