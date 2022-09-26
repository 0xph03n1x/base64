#include <iostream>
#include <algorithm>
#include <string>
#include "base64.hpp"

using namespace base64;

void to_encode(std::string user_input) {
	auto base64_decode = to_base64(user_input);
	std::cout << "Encoded message: " << base64_decode << std::endl;

}

void to_decode(std::string user_input) {
	auto base64_encode = from_base64(user_input);
	std::cout << "Decoded message: " << base64_encode << std::endl;
}

int main(int argc, char *argv[]) {

	switch(argc) {
	case 1:
		fprintf(stderr, "Usage: %s <option>\n-d - decode\n-e - encode", argv[0]);
		return 1;
	case 2:
		if (strcmp(argv[1], "-d") == 0) {
			fprintf(stderr, "Usage: base64 -d \"base64 string\"");
				return 1;
		}
		else if (strcmp(argv[1], "-e") == 0) {
			fprintf(stderr, "Usage: base64 -e \"text\"");
			return 1;
		}
		else {
			fprintf(stderr, "Right number of args, but none recognized.\n", argv[0]);
			printf("Argv0 is:%s\n", argv[0]);
			printf("Argv1 is:%s\n", argv[1]);
			return 1;
		}
	case 3:
		if (strcmp(argv[1], "-d") == 0) {
			to_decode(argv[2]);
		}
		else if (strcmp(argv[1], "-e") == 0) {
			to_encode(argv[2]);
		}
		else {
			fprintf(stderr, "Unknown command line argument %s\n", argv[1]);
			return 1;
		}
	}
	return 0;
}

/*
Thanks to https://github.com/tobiaslocker/base64 for the base64 algorithm implementation :)
*/