#pragma force_active on

typedef unsigned char u8;

struct Buf {
    char pad[0x4C];
    int count;
    u8* data;
};

struct Obj {
    char pad[0x1D0];
    Buf* buffer;
};

struct Color {
    u8 r, g, b, a;
};

extern "C" void fn_8006A170(Obj* obj, Color color) {
    Buf* c = obj->buffer;
    c->data[c->count++] = 0xC;

    c = obj->buffer;
    c->data[c->count++] = color.r;

    c = obj->buffer;
    c->data[c->count++] = color.g;

    c = obj->buffer;
    c->data[c->count++] = color.b;

    c = obj->buffer;
    c->data[c->count++] = color.a;
}
