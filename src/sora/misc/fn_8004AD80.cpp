#pragma force_active on
typedef unsigned char u8;

struct Outer {
    u8 pad[0x18];
    unsigned int* ptr;
    u8 pad2[0x8];
    u8 flags;
};

extern "C" void fn_8004AD80(Outer* self) {
    unsigned int* ptr = self->ptr;
    unsigned int r0 = 0;
    if (ptr != 0) {
        r0 = (unsigned int)__cntlzw(*ptr - 1) >> 5;
    }
    if (r0 == 0) return;
    self->flags |= 0x10;
}
