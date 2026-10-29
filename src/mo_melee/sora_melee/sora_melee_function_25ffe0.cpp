#pragma force_active on
struct G3dIface {
    virtual void v0();
    virtual void v1(int, int, int);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int);
    virtual void v7();
    virtual void v8();
};

struct Ground {
    char pad0[0x44];
    G3dIface** unk44;
    char pad48[0x10];
    unsigned int unk58;
    char pad5C[0x10];
    unsigned char unk6C;
    unsigned char unk6D;
    char pad6E[6];
};

extern "C" void updateG3dProcCalcWorld__6GroundFv(Ground* self) {
    if ((((unsigned)self->unk6D >> 3) & 1) == 1 && !((self->unk6C >> 1) & 1)) {
        unsigned long offset;
        unsigned long i = 0;
        unsigned long count = self->unk58;
        offset = 0;
        while (i != count) {
            G3dIface* obj = *(G3dIface**)((char*)self->unk44 + offset);
            obj->v6(2, 0);
            obj->v1(1, 0, 0);
            obj->v6(2, 1);
            offset += 4;
            i++;
        }
    }
    self->unk6C |= 2;
}
