#pragma once
#include <string>

enum DegreeProgram : int { SECURITY, NETWORK, SOFTWARE };
//FIXME: CREATE PARALLEL ARRAY TO RETURN STRING FOR EACH DEGREE PROGRAM
// use degree program as index
static const std::string degreeProgramStr[] = { "SECURITY", "NETWORK", "SOFTWARE" };