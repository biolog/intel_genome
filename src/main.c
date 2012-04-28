#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

int main(int argc, char *argv[]) {
enum Error ret_code = OK;
size_t threads;
size_t genome_len_min;
char *reference_file;
char **in_files_array;
size_t in_files_count;
struct buffer ref_buffer;
struct buffer in_buffer;

	if (argc < 4) {
		printf("[ERROR]: not enought input arguments");
	}

	threads = atoi(argv[1]);
	genome_len_min = atoi(argv[2]);
	reference_file = argv[3];
	in_files_array = &argv[4];
	in_files_count = argc - 4;

	Buffer_LoadFromFile(ref_buffer, reference_file);

	Buffer_Free(ref_buffer);
	return (int)ret_code;
}

