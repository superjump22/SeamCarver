//
//  config.hpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#ifndef config_hpp
#define config_hpp

#include <string>

using std::string;

#ifdef XCODE
const string INPUTS_DIRECTORY = "../../../Inputs/";
const string OUTPUTS_DIRECTORY = "../../../Outputs/";
#else
const string INPUTS_DIRECTORY = "../Inputs/";
const string OUTPUTS_DIRECTORY = "../Outputs/";
#endif

#endif /* config_hpp */
