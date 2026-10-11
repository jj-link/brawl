typedef unsigned long size_t;

extern size_t __fwrite(const void* data, size_t size, size_t count, void* stream);

/* Formatting output succeeds only when the entire span reaches the stream. */
void* __FileWrite(void* stream, const char* data, size_t count) {
    return __fwrite(data, 1, count, stream) == count ? stream : 0;
}
