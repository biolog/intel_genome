#include <stdlib.h>
#include "buffer.h"

enum BufferError Buffer_LoadFromFile(struct buffer *buffer, char *filename)
{
	// TODO: we must remember, how many threads we can start
	return BUFFER_OK;
}

void Buffer_Free(struct buffer *buffer)
{
	if (buffer->data != NULL)
		free(buffer->data);
}

