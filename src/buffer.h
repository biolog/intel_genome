#pragma once

enum BufferError{
	BUFFER_OK,
	BUFFER_LOAD_FAIL
};

struct buffer{
	size_t length
	char *data,
};

enum BufferError Buffer_LoadFromFile(struct buffer *buffer, char *filename);

void Buffer_Free(struct buffer *buffer);


