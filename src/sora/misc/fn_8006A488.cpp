#pragma force_active on
#include <types.h>

struct Buffer {
    char pad[0x4C];
    int count;
    u8* data;
};
struct Object {
    char pad[0x1D0];
    Buffer* buffer;
};
struct Color { u8 r, g, b, a; };
extern const f32 lbl_805A1A00;

extern "C" void fn_8006A488(Object* obj, Color color, f32 f) {
    u32 packed = (color.b << 8) + ((color.r << 24) + (color.g << 16));
    Buffer* b = obj->buffer;
    b->data[b->count++] = 0x11;
    Buffer* b1 = obj->buffer;
    b1->data[b1->count++] = (u8)(int)(lbl_805A1A00 * f);
    b = obj->buffer;
    b->data[b->count++] = packed >> 24;
    b = obj->buffer;
    b->data[b->count++] = packed >> 16;
    b = obj->buffer;
    b->data[b->count++] = packed >> 8;
}