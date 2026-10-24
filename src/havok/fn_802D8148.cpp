#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802DA2B4(void*);
extern unsigned char lbl_80487B10[];
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
};

struct Obj {
    void* vtable;
    unsigned short type;
    char pad[0x6];
    Array a;
    char pad2[0x14];
    void* p2c;
};

extern "C" Obj* fn_802D8148(Obj* self, int flag) {
    if (self) {
        void* p = self->p2c;
        self->vtable = lbl_80487B10;
        if (p) {
            fn_802DA2B4(p);
        }
        if ((char*)&self->a && (char*)&self->a && (char*)&self->a && self->a.isOwned()) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.raw & 0x3FFFFFFF, 0x15);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x2A);
        }
    }
    return self;
}
