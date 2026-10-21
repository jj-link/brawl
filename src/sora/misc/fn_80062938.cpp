#pragma force_active on
struct FnObj58 {
    char pad[0x58];
    unsigned char flags;
};

extern "C" void fn_80062938(FnObj58* obj) {
    unsigned char f = obj->flags;
    if (!(f & 0x08)) {
        obj->flags = (f & ~0x04) | 0x02;
    }
}
