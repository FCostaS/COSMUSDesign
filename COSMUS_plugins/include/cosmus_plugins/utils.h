/* Copyright (c) 2017, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 *
 * All rights reserved.
 *
 * The Astrobee platform is licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <regex>
#include <random>
#include <limits>

#define MAX_BUFFER_SIZE 512
#define TOPIC_WIFI_TRANSMITTER_MAP "transmitter"
#define FRAME_NAME_BODY "body"
#define DEFAULT_RATE 100
#define TOPIC_NAME_RSSI "wifi_receiver/wifi_scan"
#define TOPIC_NAME_DATA_RECEIVER "wifi_receiver/data"
#define DEFAULT_NOISE_FLOOR -340
#define DEFAULT_BYTE_NUM 40
#define DEFAULT_FREQ_COMM 2441

#endif  // UTILS_H_

std::regex regex_lang("\\/");

std::string tokenizer(std::string s) {
  std::vector<std::string> out(
                  std::sregex_token_iterator(s.begin(),
                  s.end(),
                  regex_lang, -1),
                  std::sregex_token_iterator());
  return out[out.size()-1];
}

/* HELPER METHODS */
/////////////////////////////////////////////
inline double dbmToPow(double x) { return 0.001 * pow(10., x / 10.); }

/////////////////////////////////////////////
inline double QPSKPowerToBER(double P, double N) { return erfc(sqrt(P / N)); }
