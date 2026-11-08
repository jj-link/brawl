#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Vec {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};

struct Obj {
    char pad[0x58];
    Vec a;
    Vec b;
};

extern "C" void fn_802E8E40(Obj* o) {
    if (o->a.size == 0) {
        o->a.clear();
    }
    if (o->b.size == 0) {
        o->b.clear();
    }
}
