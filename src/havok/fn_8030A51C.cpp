#pragma force_active on
extern void* lbl_805A0EC8;
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

struct Class_8030A51C {
    void* unk0;
    int pad4;
    unsigned int unk8;

    bool isOwned() const {
        return (unk8 & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, unk0, unk8 << 2, 0x15);
    }
};

extern "C" Class_8030A51C* __dt__14Class_8030A51CFv(Class_8030A51C* self) {
    if (self != 0 && self != 0 && self->isOwned()) {
        self->dealloc();
    }
    return self;
}
