#pragma force_active on
extern "C" void fn_80082544(int, int);
extern "C" void fn_8027BCE0();
extern "C" void fn_8027E9E0(void*);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Ref {
    virtual void v2(int, int);
};

struct Timer {
    virtual void v2(int);
    unsigned short m4;
    short m6;
};

struct Alloc {
    virtual void v0();
    virtual void v3(void*);
};

extern Alloc* lbl_805A0EB8;

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
    char p0[0x47];
    unsigned char m47;
    Ref* m48;
    void* m4C;
    void* m50;
    Timer* m54;
    int m58;
    unsigned char m5C;
    Vec v1;
    Vec v2;
    unsigned char m78;
};

extern "C" void fn_8009A540(Obj* self) {
    if (self->m5C != 0) {
        self->m78 = 1;
        if (self->v1.size == 0) {
            self->v1.clear();
        }
        if (self->v2.size == 0) {
            self->v2.clear();
        }
        if (self->m58 != 0 && self->v1.size == 0) {
            fn_80082544(self->m58, 1);
            self->m58 = 0;
        }
    } else {
        if (self->m78 != 0) {
            Timer* t = self->m54;
            if (t != 0) {
                if (t->m4 != 0) {
                    t->m6 = t->m6 - 1;
                    if (t->m6 == 0 && t != 0) {
                        t->v2(1);
                    }
                }
                self->m54 = 0;
            }
            if (self->m58 != 0 && self->v1.size == 0) {
                fn_80082544(self->m58, 1);
                self->m58 = 0;
            }
            self->m78 = 0;
        }
    }
    Timer* t2 = self->m54;
    if (t2 != 0) {
        if (t2->m4 != 0) {
            t2->m6 = t2->m6 - 1;
            if (t2->m6 == 0 && t2 != 0) {
                t2->v2(1);
            }
        }
        self->m54 = 0;
    }
    self->m48->v2(0, 0);
    lbl_805A0EB8->v3(self->m4C);
    fn_8027E9E0(self->m48);
    fn_8027BCE0();
    self->m47 = 0;
}
