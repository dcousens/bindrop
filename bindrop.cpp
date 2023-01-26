#include <cstdint>
#include <cstdio>
#include <cstring>

int error (char const* message) {
	fprintf(stderr, "%s\n", message);
	return 1;
}

int main (int argc, char** argv) {
	if (argc != 4) return error("invalid number of arguments");

	size_t start = 0;
	size_t end = 0;
	size_t count = 0;

	// eg. 2 22 24, drop bytes[2:22], 24 total bytes
	if (sscanf(argv[1], "%lu", &start) != 1) return error("bad start offset");
	if (sscanf(argv[2], "%lu", &end) != 1) return error("bad end offset");
	if (sscanf(argv[3], "%lu", &count) != 1) return error("bad count");
	if (start > end) return error("start offset exceeds end");
	if (end > count) return error("end offset exceeds count");
	if (end == 0) return error("end offset should be greater than 0");

	auto const slice = new uint8_t[count];

	while (fread(slice, count, 1, stdin) == 1) {
		fwrite(slice, start, 1, stdout);
		fwrite(slice + end, count - end, 1, stdout);
	}

	return 0;
}
