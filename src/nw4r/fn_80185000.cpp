#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Color {
    u8 r, g, b, a;
};

struct Object;

extern "C" void fn_80185048(Object* object, int index, const Color* color);

extern "C" void fn_80185000(Object* object, u32 index, const Color* color) {
    Color copy = *color;
    fn_80185048(object, index >> 1, &copy);
}
