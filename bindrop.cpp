#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

int main (int argc, char** argv) {
	assert(argc == 3 || argc == 4);

	size_t dropOffset = 0;
	size_t dropBytes = 0;
	size_t totalBytes = 0;

	// eg. 20 40, drop bytes[0:20], 40 total bytes
	if (argc == 3) {
		assert(sscanf(argv[1], "%lu", &dropBytes) == 1);
		assert(sscanf(argv[2], "%lu", &totalBytes) == 1);
	}

	// eg. 2 22 24, drop bytes[2:22], 24 total bytes
	if (argc == 4) {
		assert(sscanf(argv[1], "%lu", &dropOffset) == 1);
		assert(sscanf(argv[2], "%lu", &dropBytes) == 1);
		assert(dropBytes >= dropOffset);
		dropBytes = dropBytes - dropOffset;
		assert(sscanf(argv[3], "%lu", &totalBytes) == 1);
	}

	assert(dropBytes > 0);
	assert(dropOffset < totalBytes);

	const auto slice = new uint8_t[totalBytes];

	while (fread(slice, totalBytes, 1, stdin) == 1) {
		fwrite(slice, dropOffset, 1, stdout);
		fwrite(slice + dropOffset + dropBytes, totalBytes - dropBytes, 1, stdout);
	}

	return 0;
}
