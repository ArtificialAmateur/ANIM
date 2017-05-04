//============================================================================
// Name        : mitmap.cpp
// Author      : @ArtificialAmateur @alefir
// Version     : 0.0.1a
// Copyright   : dont steal our things
// Description : Man In The Middle Access Point
//============================================================================

#include <iostream>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <string>

std::string char_to_string(char val) {
	std::stringstream ss;
	std::string s;
	ss << val;
	ss >> s;
	return s;	
}

std::vector<std::string> split(const std::string &text, char* sep) {
  std::vector<std::string> tokens;
  std::size_t start = 0, end = 0;
  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

char run_command(char* command) {
	FILE *fpipe;
    char c = 0;

    if(0 == (fpipe = (FILE*)popen(command, "r"))) {
        perror("popen() failed.");
        exit(1);
    }
    while (fread(&c, sizeof c, 1, fpipe)) {
        return c;
    }
    pclose(fpipe);
    return c;
}

int main(int argc, char* argv[]) {
	char output[20] = { run_command("uname -a") };
	std::string uname = output;
	std::cout << uname << std::endl;
	std::cout << output << std::endl;
	std::string kernel = split(uname, " ")[2];
	std::cout << kernel << std::endl;
	return 0;
}
