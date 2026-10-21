#pragma force_active on
typedef unsigned char u8;

struct Color {
    u8 r, g, b, a;
};

struct Object {
    u8 pad[0xE4];
    Color colors[1];
};

extern "C" void fn_80185C78(Object* base, int idx, const Color* src) {
    base->colors[idx] = *src;
}
