#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Buffer {
    char pad[0x4C];
    int count;
    u8* data;
};

struct Object {
    char pad[0x1D0];
    Buffer* buffer;
};

extern "C" void fn_8006A31C(Object* obj, u32 value) {
    Buffer* b = obj->buffer;
    b->data[b->count++] = 4;
    b = obj->buffer;
    b->data[b->count++] = value >> 24;
    b = obj->buffer;
    b->data[b->count++] = (value >> 16) & 0xFF;
    b = obj->buffer;
    b->data[b->count++] = (value >> 8) & 0xFF;
    b = obj->buffer;
    b->data[b->count++] = value;
}
