#pragma force_active on
struct Obj {
    char pad[0x18];
    int flags;
};

struct Entry {
    char data[0xC];
};

extern "C" {
Entry* fn_27_F8D9C(Obj* self, int idx) {
    int r = (self->flags >> 26) + idx;
    if (r >= 0x17) {
        r -= 0x17;
    }
    return (Entry*)((char*)self + 0x1c + r * 12);
}
}
