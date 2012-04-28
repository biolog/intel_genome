#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "buffer.h"

/*****************************************************************************/
/* PUBLIC FUNCTIONS                                                          */
/*****************************************************************************/
// TODO: we must remember, how many threads we can start
enum BufferError Buffer_MapFile(struct buffer *buffer, char *filename)
{
struct stat st;
size_t file_length;
int fd;

	stat(filename, &st);
	file_length = st.st_size;
	buffer->length = file_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return BUFFER_LOAD_FAIL;

	buffer->data = mmap(NULL, file_length, PROT_READ, MAP_SHARED, fd, 0L);
	if (buffer->data == MAP_FAILED)
		return BUFFER_LOAD_FAIL;

	close(fd);
	return BUFFER_OK;
}

void Buffer_Free(struct buffer *buffer)
{
	if (buffer->data != NULL || buffer->data != MAP_FAILED)
		munmap(buffer->data, buffer->length);
}

