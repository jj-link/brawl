#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

struct Obj {
    unsigned char pad[0xE4];
    Color colors[1];
};

extern "C" void fn_80185C4C(Color* out, const Obj* base, unsigned int idx) {
    *out = base->colors[idx];
}
