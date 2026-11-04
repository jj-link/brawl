#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* __dt__14Class_802F0BECFv(void*, int);
extern void* lbl_805A0EC8;
extern unsigned char lbl_80488CF4[];

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

class P2cClass {
public:
    virtual void vf0(int);
};

struct Object {
    void* vtable;
    unsigned short type;
    char pad[0x22];
    void* data;
    int size;
    unsigned int raw;
    P2cClass* p2c;

    unsigned int rawValue() const {
        return raw;
    }
};

extern "C" Object* fn_80326124(Object* self, int flag) {
    if (self) {
        P2cClass* p = self->p2c;
        self->vtable = lbl_80488CF4;
        if (p) {
            p->vf0(1);
        }
        if ((unsigned int)self + 0x28 != 0 && !(self->raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->data, self->rawValue() << 6, 0x15);
        }
        __dt__14Class_802F0BECFv(self, 0);
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x13);
        }
    }
    return self;
}