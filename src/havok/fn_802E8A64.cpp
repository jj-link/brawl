#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

struct Heap {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();

    int a, b, c;
    unsigned int f10;
    int f14;
    unsigned int f18;
};

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned short, int);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern Heap* lbl_805A0EC8;

struct Array {
    void* data;
    int size;
    unsigned int raw;
    unsigned int f0c;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 3, 0x15);
    }

    ~Array() {
        if (isOwned())
            dealloc();
    }
};

extern "C" Array* __dt__14Class_802E8A64Fv(Array* self, int flag) {
    if (self) {
        unsigned int v = self->f0c;
        Heap* h = lbl_805A0EC8;
        h->f10 = v;
        if (v == h->f18)
            h->v4();

        self->~Array();

        if (flag > 0)
            lbl_805A0EB8->free(self, 0x10, 0x15);
    }
    return self;
}
