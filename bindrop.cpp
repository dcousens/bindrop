#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

int main (int argc, char** argv) {
	assert(argc == 4);

	size_t dropStart = 0;
	size_t dropEnd = 0;
	size_t totalBytes = 0;

	// eg. 2 22 24, drop bytes[2:22], 24 total bytes
	if (argc == 4) {
		assert(sscanf(argv[1], "%lu", &dropStart) == 1);
		assert(sscanf(argv[2], "%lu", &dropEnd) == 1);
		assert(dropEnd >= dropStart);
		assert(sscanf(argv[3], "%lu", &totalBytes) == 1);
	}

	assert(dropEnd > 0);
	assert(dropStart < totalBytes);

	auto const slice = new uint8_t[totalBytes];

	while (fread(slice, totalBytes, 1, stdin) == 1) {
		fwrite(slice, dropStart, 1, stdout);
		fwrite(slice + dropEnd, totalBytes - dropEnd, 1, stdout);
	}

	return 0;
}
