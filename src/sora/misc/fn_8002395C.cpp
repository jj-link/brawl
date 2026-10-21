#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Entry {
    u32 zero;
    u8* data;
};

struct Buffer {
    s16 height;
    u16 width;
    u8 count;
    u8 pad[7];
    Entry entries[1];
};

extern "C" void fn_8002395C(Buffer* self, u32 count, int width, s16 height, u8* data) {
    self->count = count;
    self->height = height;
    self->width = width;

    u32 size = (u16)(((u16)width + 15) & 0xFFF0) * height * 2;

    for (u32 i = 0; i < count; i++) {
        self->entries[i].zero = 0;
        self->entries[i].data = data;
        data += size;
    }
}
