#pragma force_active on
typedef unsigned char u8;

struct Color {
    u8 r, g, b, a;
};

struct Object {
    u8 pad[0xD4];
    Color colors[1];
};

extern "C" void fn_801849A4(Object* obj, int index, const Color* color) {
    obj->colors[index] = *color;
}
