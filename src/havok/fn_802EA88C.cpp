#pragma force_active on

extern "C" {
extern void fn_8027EABC(void*, void*, unsigned int, int);
extern void fn_802ECBC0(void*, void*);
extern void fn_802EDFBC(void*, void*);
extern void fn_802FAD24(void*, void*);
extern void fn_802F4658(void*);
extern void fn_802CAE60(void*, int);
extern void fn_802F5D88(void*, int);
extern char lbl_80488320[];
extern void* lbl_805A0EC8;
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

class Ref {
public:
    virtual void destroy(int);
    unsigned short active;
    short refs;
};

struct Array {
    void* data;
    int count;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    void dealloc16() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 4, 0x15);
    }
};

struct Obj {
    void* vtable;
    unsigned short type;
};

extern "C" Obj* fn_802EA88C(Obj* self, int arg1) {
    char* b = (char*)self;
    if (self != 0) {
        Ref* p4c = *(Ref**)(b + 0x4c);
        self->vtable = lbl_80488320;
        if (p4c->active != 0) {
            p4c->refs = p4c->refs - 1;
            if (p4c->refs == 0 && p4c != 0) p4c->destroy(1);
        }
        void* p9c = *(void**)(b + 0x9c);
        *(void**)(b + 0x4c) = 0;
        if (p9c != 0) {
            if (p9c != 0) lbl_805A0EB8->free(p9c, 1, 0x13);
            *(void**)(b + 0x9c) = 0;
        }
        void* pa4 = *(void**)(b + 0xa4);
        if (pa4 != 0) {
            if (pa4 != 0) lbl_805A0EB8->free(pa4, 1, 0x13);
            *(void**)(b + 0xa4) = 0;
            int off;
            int i = 0;
            for (off = 0; i < *(int*)(b + 0xac); off += 16, i++) {
                void* q = *(void**)(*(char**)(b + 0xa8) + off + 0xc);
                if (q != 0) lbl_805A0EB8->free(q, 1, 0x13);
            }
            *(int*)(b + 0xac) = 0;
        }
        void* pa0 = *(void**)(b + 0xa0);
        if (pa0 != 0) {
            if (pa0 != 0) lbl_805A0EB8->free(pa0, 1, 0x13);
            *(void**)(b + 0xa0) = 0;
        }
        Ref* p50 = *(Ref**)(b + 0x50);
        if (p50 != 0) {
            if (p50->active != 0) {
                p50->refs = p50->refs - 1;
                if (p50->refs == 0 && p50 != 0) p50->destroy(1);
            }
            *(void**)(b + 0x50) = 0;
        }
        while (*(int*)(b + 0xd0) > 0) {
            fn_802EDFBC(self, *(void**)*(void**)(b + 0xcc));
        }
        char* obj = 0;
        while (*(int*)(b + 0x2c) > 0 && *(int*)((obj = (char*)(*(void***)(b + 0x28))[0]) + 0x3c) != 0) {
            fn_802ECBC0(self, *(void**)*(void**)(obj + 0x38));
        }
        while (*(int*)(b + 0x38) > 0) {
            void** arr = *(void***)(b + 0x34);
            fn_802ECBC0(self, *(void**)*(void**)((char*)arr[0] + 0x38));
        }
        if (*(signed char*)(b + 0xb4) == 0) {
            fn_802FAD24(self, (*(void***)(b + 0x28))[*(int*)(b + 0x2c) - 1]);
            Ref* rx = (Ref*)(*(void***)(b + 0x28))[*(int*)(b + 0x2c) - 1];
            if (rx != 0) rx->destroy(1);
            *(int*)(b + 0x2c) = *(int*)(b + 0x2c) - 1;
        }
        fn_802ECBC0(self, *(void**)(b + 0x24));
        *(void**)(b + 0x24) = 0;
        while (*(int*)(*(char**)(b + 0x20) + 0x3c) > 0) {
            fn_802ECBC0(self, *(void**)*(void**)(*(char**)(b + 0x20) + 0x38));
        }
        fn_802FAD24(self, *(void**)(b + 0x20));
        Ref* r20 = *(Ref**)(b + 0x20);
        if (r20 != 0) r20->destroy(1);
        *(void**)(b + 0x20) = 0;
        fn_802F4658(self);
        Ref* p54 = *(Ref**)(b + 0x54);
        if (p54->active != 0) {
            p54->refs = p54->refs - 1;
            if (p54->refs == 0 && p54 != 0) p54->destroy(1);
        }
        *(void**)(b + 0x54) = 0;
        Ref* p70 = *(Ref**)(b + 0x70);
        if (p70->active != 0) {
            p70->refs = p70->refs - 1;
            if (p70->refs == 0 && p70 != 0) p70->destroy(1);
        }
        *(void**)(b + 0x70) = 0;
        fn_802CAE60(*(void**)(b + 0x58), 1);
        Ref* p168 = *(Ref**)(b + 0x168);
        if (p168 != 0) {
            if (p168->active != 0) {
                p168->refs = p168->refs - 1;
                if (p168->refs == 0 && p168 != 0) p168->destroy(1);
            }
        }
        Ref* p5c = *(Ref**)(b + 0x5c);
        if (p5c != 0) p5c->destroy(1);
        Ref* p60 = *(Ref**)(b + 0x60);
        if (p60 != 0) p60->destroy(1);
        Ref* p64 = *(Ref**)(b + 0x64);
        if (p64 != 0) p64->destroy(1);
        Ref* p6c = *(Ref**)(b + 0x6c);
        if (p6c->active != 0) {
            p6c->refs = p6c->refs - 1;
            if (p6c->refs == 0 && p6c != 0) p6c->destroy(1);
        }
        lbl_805A0EB8->free(*(void**)(*(char**)(b + 0x68) + 0x20), 8, 0x1d);
        lbl_805A0EB8->free(*(void**)(b + 0x68), 0x30, 0x1d);
        Ref* p8 = *(Ref**)(b + 0x8);
        if (p8->active != 0) {
            p8->refs = p8->refs - 1;
            if (p8->refs == 0 && p8 != 0) p8->destroy(1);
        }
        fn_802F5D88(*(void**)(b + 0x74), 1);
        if ((char*)self + 0x15c != 0 && ((Array*)(b + 0x15c))->isOwned()) ((Array*)(b + 0x15c))->dealloc();
        if ((char*)self + 0x150 != 0 && ((Array*)(b + 0x150))->isOwned()) ((Array*)(b + 0x150))->dealloc();
        if ((char*)self + 0x144 != 0 && ((Array*)(b + 0x144))->isOwned()) ((Array*)(b + 0x144))->dealloc();
        if ((char*)self + 0x138 != 0 && ((Array*)(b + 0x138))->isOwned()) ((Array*)(b + 0x138))->dealloc();
        if ((char*)self + 0x12c != 0 && ((Array*)(b + 0x12c))->isOwned()) ((Array*)(b + 0x12c))->dealloc();
        if ((char*)self + 0x120 != 0 && ((Array*)(b + 0x120))->isOwned()) ((Array*)(b + 0x120))->dealloc();
        if ((char*)self + 0x114 != 0 && ((Array*)(b + 0x114))->isOwned()) ((Array*)(b + 0x114))->dealloc();
        if ((char*)self + 0x108 != 0 && ((Array*)(b + 0x108))->isOwned()) ((Array*)(b + 0x108))->dealloc();
        if ((char*)self + 0xfc != 0 && ((Array*)(b + 0xfc))->isOwned()) ((Array*)(b + 0xfc))->dealloc();
        if ((char*)self + 0xf0 != 0 && ((Array*)(b + 0xf0))->isOwned()) ((Array*)(b + 0xf0))->dealloc();
        if ((char*)self + 0xe4 != 0 && ((Array*)(b + 0xe4))->isOwned()) ((Array*)(b + 0xe4))->dealloc();
        if ((char*)self + 0xd8 != 0 && ((Array*)(b + 0xd8))->isOwned()) ((Array*)(b + 0xd8))->dealloc();
        if ((char*)self + 0xcc != 0 && ((Array*)(b + 0xcc))->isOwned()) ((Array*)(b + 0xcc))->dealloc();
        if ((char*)self + 0xa8 != 0 && ((Array*)(b + 0xa8))->isOwned()) ((Array*)(b + 0xa8))->dealloc16();
        if ((char*)self + 0x40 != 0 && ((Array*)(b + 0x40))->isOwned()) ((Array*)(b + 0x40))->dealloc();
        if ((char*)self + 0x34 != 0 && ((Array*)(b + 0x34))->isOwned()) ((Array*)(b + 0x34))->dealloc();
        if ((char*)self + 0x28 != 0 && ((Array*)(b + 0x28))->isOwned()) ((Array*)(b + 0x28))->dealloc();
        if (arg1 > 0) {
            lbl_805A0EB8->free(self, *(unsigned short*)(b + 4), 0x2d);
        }
    }
    return self;
}
