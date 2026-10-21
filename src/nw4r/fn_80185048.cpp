#pragma force_active on
typedef unsigned char u8;

struct Color {
    u8 r, g, b, a;
};

struct Object {
    u8 padding[0xD8];
    Color colors[1];
};

extern "C" void fn_80185048(Object* object, int index, const Color* color) {
    object->colors[index] = *color;
}
