#pragma force_active on

extern "C" int OSIsThreadTerminated(void* thread);

struct Obj {
    unsigned char pad0[0x58];
    void* t58;
    unsigned char flag5c;
    unsigned char pad1[0x188 - 0x5D];
    void* t188;
    int f18c;
    int f190;
};

extern "C" int fn_800390C8(Obj* __restrict self) {
    int r;
    if (self->flag5c == 0) {
        return 0;
    }
    if (self->f18c != 0 || self->f190 != 0) {
        return 0;
    }
    if (self->t188 != 0) {
        r = (OSIsThreadTerminated((char*)self->t188 + 8) - 1) == 0;
        if (!r) {
            return 0;
        }
    }
    if (self->t58 != 0) {
        r = (OSIsThreadTerminated((char*)self->t58 + 8) - 1) == 0;
        if (!r) {
            return 0;
        }
    }
    return 1;
}
