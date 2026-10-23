#pragma force_active on

typedef unsigned char u8;

struct Buffer {
    char pad[0x4C];
    int count;
    u8* data;
};

struct Color {
    u8 r, g, b, a;
};

struct Object {
    char pad[0x1D0];
    Buffer* buffer;
};

extern "C" void fn_8006A28C(Object* obj, Color color) {
    Buffer* b = obj->buffer;
    b->data[b->count++] = 4;
    b = obj->buffer;
    b->data[b->count++] = color.r;
    b = obj->buffer;
    b->data[b->count++] = color.g;
    b = obj->buffer;
    b->data[b->count++] = color.b;
    b = obj->buffer;
    b->data[b->count++] = color.a;
}
