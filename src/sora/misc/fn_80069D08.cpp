#pragma force_active on
typedef unsigned char u8;

struct Buffer {
    char pad[0x4C];
    int count;
    u8* data;
};

struct Object {
    char pad[0x1D0];
    Buffer* buffer;
};

extern "C" void fn_80069D08(Object* obj, u8 value) {
    Buffer* b = obj->buffer;
    b->data[b->count++] = 5;
    b = obj->buffer;
    b->data[b->count++] = value;
}
