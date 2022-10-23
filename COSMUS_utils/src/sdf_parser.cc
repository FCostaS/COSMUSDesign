/*
 * Copyright 2015 James Jackson MAGICC Lab, BYU, Provo, UT
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * The airspeed aircraft plugin is adapted from package https://github.com/byu-magicc/rosflight_plugins.git
 * with all credits attributed to the developer.
 */

#ifndef SDF_NODE_H
#define SDF_NODE_H

#include <random>
#include <chrono>
#include <cmath>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

//#include <ros/ros.h>
//#include <gazebo/common/common.hh>
//#include <gazebo/common/Plugin.hh>
//#include <gazebo/gazebo.hh>
//#include <gazebo/physics/physics.hh>
//#include <sdf/parser.hh>
//#include <sdf/sdf.hh>
#include <regex>

using namespace std;

std::regex regex_lang("\\:=");

std::vector<std::string> split(std::string s) {
  std::vector<std::string> out(
                  std::sregex_token_iterator(s.begin(),
                  s.end(),
                  regex_lang, -1),
                  std::sregex_token_iterator());
  return out;
}

int main(int argc, char **argv) {
  // Read an SDF file, and store the result in sdf.
  // sdf::Errors errors;

  // Read an SDF file, and store the result in sdfParsed.
  // sdf::SDFPtr sdfParsed = sdf::readFile(argv[1], errors);

  // open sdf file
  ifstream in(argv[1]);
  std::vector<std::string> param = split(argv[2]);
  string param_name(param[0]);
  string param_value(param[1]);

  string line, sdf_out;
  size_t len = param_name.length();

  while (getline(in, line)) {
      while (true) {
          size_t pos = line.find(param_name);
          if (pos != string::npos) {
              line.replace(pos, len, param_value);
          } else {
              break;
          }
      }
      sdf_out.append(line);
  }
  cout << sdf_out << endl;
  in.close();
  //return 1;
}

#endif
