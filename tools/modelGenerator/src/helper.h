/*
  This Source Code Form is "Incompatible With Secondary Licenses," as
  defined by the Mozilla Public License, v. 2.0.

  This specific component is licensed under the GNU General Public License
  (GPL). Please refer to the 'LICENSE' file in this directory for the
  applicable terms of the GPL.

    Copyright (C) 2024 contributers

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> split(std::string string, char splitter);

struct point
{
    float x;
    float y;
    float z;
};

struct vertex
{
    int from;
    int to;
};

point generatePoint(std::string string);
std::vector<vertex> generateEdgesFromFace(std::string faceString);
