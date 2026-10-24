#pragma force_active on
typedef unsigned long size_t;
typedef unsigned long fpos_t;
typedef int (*WriteFn)(unsigned long, unsigned char*, size_t*, void*);

typedef struct File {
    unsigned long handle;
    char pad04[0x14];
    fpos_t position;
    unsigned char* buffer;
    size_t buffer_size;
    unsigned char* buffer_ptr;
    size_t buffer_len;
    unsigned long buffer_alignment;
    size_t save_buffer_len;
    fpos_t buffer_pos;
    void* read_proc;
    void* extra3c;
    WriteFn write_proc;
    void* extra44;
    void* refcon;
} File;

int __flush_buffer(File* file, size_t* length) {
    size_t buffer_len;
    int ioresult;

    buffer_len = file->buffer_ptr - file->buffer;
    if (buffer_len != 0) {
        file->buffer_len = buffer_len;
        ioresult = file->write_proc(file->handle, file->buffer,
                                   &file->buffer_len, file->refcon);
        if (length != 0)
            *length = file->buffer_len;
        if (ioresult != 0)
            return ioresult;
        file->position += file->buffer_len;
    }
    file->buffer_ptr = file->buffer;
    file->buffer_len = file->buffer_size;
    file->buffer_len -= file->position & file->buffer_alignment;
    file->buffer_pos = file->position;
    return 0;
}
