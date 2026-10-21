#pragma force_active on
struct Obj {
    int pad[3];
    unsigned int mC;
};

extern "C" void fn_8019DA5C(Obj* self, unsigned int mask, int flag) {
    if (flag != 0) {
        self->mC |= mask;
    } else {
        self->mC &= ~mask;
    }
}
