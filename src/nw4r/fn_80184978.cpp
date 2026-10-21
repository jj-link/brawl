#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

struct Obj {
    unsigned char pad[0xD4];
    Color colors[1];
};

extern "C" void fn_80184978(Color* out, const Obj* base, unsigned int idx) {
    *out = base->colors[idx];
}
