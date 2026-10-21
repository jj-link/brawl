#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern unsigned char lbl_80488300[];
extern void* lbl_805A0EC8;

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

struct Array {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    ~Array() {
        if (isOwned())
            dealloc();
    }
};

struct Array1 : Array {
    ~Array1() {}
};

struct Array2 : Array1 {
    ~Array2() {}
};

struct Object {
    void* vtable;
    unsigned short type;
    char pad[0x32];
    Array1 a38;
    int f44;
    Array2 a48;
    char pad54[0xC];
    Array a60;
};

extern "C" Object* fn_802E9CF8(Object* self, int flag) {
    if (self) {
        self->vtable = lbl_80488300;
        self->a60.~Array();
        self->a48.~Array2();
        self->a38.~Array1();

        if (flag > 0)
            lbl_805A0EB8->free(self, self->type, 0x30);
    }

    return self;
}
