#include <stdlib.h>
#include <stdio.h>
#include "defines.h"

int main (int argc, char *argv[]) {
enum Error ret_code = OK;
enum BufferError buf_ret_code;
size_t threads;
size_t genome_len_min;
char *reference_file;
char **in_files_array;
size_t in_files_count;
struct buffer ref_buffer;
struct buffer in_buffer;
size_t i;

	if (argc < 4) {
		printf("[ERROR]: not enought input arguments");
	}

	threads = atoi (argv[1]);
	genome_len_min = atoi (argv[2]);
	reference_file = argv[3];
	in_files_array = &argv[4];
	in_files_count = argc - 4;

	buf_ret_code = Buffer_MapFile (&ref_buffer, reference_file);
	if (buf_ret_code != BUFFER_OK) {
		ret_code = 
	}

	for (i = 0; i < in_files_count; i++) {
		Buffer_MapFile(&in_buffer, in_files_array[i]);
		Compare()
	}

	Buffer_Free(&ref_buffer);
	return (int)ret_code;
}

