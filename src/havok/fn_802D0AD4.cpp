#pragma force_active on

extern "C" {
extern char lbl_804873E8[];
}

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

struct Ref {
    virtual void f0(int);
    unsigned short active;
    short refs;
};

struct Base {
    void* vt;
    Ref* ref;
};

struct Obj {
    void* vt;
    unsigned short type;
    char pad[0xA];
    Base base;
};

extern "C" Obj* fn_802D0AD4(Obj* self, int flag) {
    if (self != 0) {
        if ((unsigned int)self + 0x10) {
            self->base.vt = lbl_804873E8;
            Ref* ref = self->base.ref;
            if (ref->active != 0) {
                ref->refs = ref->refs - 1;
                if (ref->refs == 0 && ref != 0) {
                    ref->f0(1);
                }
            }
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x25);
        }
    }
    return self;
}
