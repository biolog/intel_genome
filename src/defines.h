#pragma once
#include "buffer.h"

enum Error {
	OK,
	LOAD_INPUT_FILE_FAILS
};

struct result{
	size_t ref_start;
	size_t ref_end;
	size_t in_start;
	size_t in_end;
};

enum Error Compare(
	struct buffer *ref_buffer,
	struct buffer *in_buffer,
	size_t threads_avaliable,
	struct result *results);

