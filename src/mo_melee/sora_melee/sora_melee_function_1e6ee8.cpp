#pragma force_active on
struct Slot {
    int a;
    int b;
    int c;
};

struct Obj {
    unsigned char pad[0x18];
    int flags;
};

extern "C" {
Slot* fn_27_1E6EE8(Obj* self, int idx)
{
    int r = (self->flags >> 28) + idx;
    if (r >= 7) {
        r -= 7;
    }
    return (Slot*)((char*)self + 0x1c + r * 12);
}
}
