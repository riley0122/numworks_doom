/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
#pragma once

struct position4D
{
    float x;
    float y;
    float z;
    float w;
};


struct position
{
    float x;
    float y;
    float z;
};

struct position2D
{
    float x;
    float y;
};

struct angular
{
    float pitch;
    float yaw;
};

struct vertex
{
    int start;
    int end;
};
