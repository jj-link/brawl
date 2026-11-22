#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802CB04C(void*, void*);
extern "C" void fn_802CAFC0(void*, void*, int);
extern "C" void fn_802CAEE8(void*, void*, int, void*);
extern "C" void fn_802EFE70(void*);
extern "C" void fn_802EFF2C(void*, void*);

class Alloc {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual unsigned int s3(unsigned int);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    char pad[0xc];
    unsigned int cur;
    unsigned int padx;
    unsigned int lim1;
    unsigned int lim2;
};
extern Alloc* lbl_805A0EC8;
extern float lbl_805A4540;

struct Arr {
    unsigned int data;
    int size;
    unsigned int cap;
    unsigned int orig;
    unsigned int isUnowned() const { return cap & 0x80000000; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, (void*)data, cap << 3, 0x15); }
};

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(void*, void*, float);
};
class Obj2 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7(void*, void*, int, void*, void*);
};
struct Sub { char p[8]; float f; };
struct Ctx {
    char p[0x54];
    Obj2* u54;
    void* u58;
    char p2[0xc];
    Sub* u68;
    char* u6c;
    char p3[0x8];
    int u78;
    int u7c;
    char p4[4];
    signed char u84;
    char p5[0x25f];
    int u2e4;
};
struct In {
    char p[0x1c];
    Obj* u1c;
    char p2[4];
    void* u24;
    char p3[8];
    char u30[4];
};

static inline void mk(Arr& a, int n) {
    a.data = 0; a.size = 0; a.cap = 0x80000000;
    unsigned int r = lbl_805A0EC8->cur;
    unsigned int bytes = (n * 8 + 0x10) & ~0xf;
    unsigned int e = r + bytes;
    if (e <= lbl_805A0EC8->lim2) lbl_805A0EC8->cur = e;
    else r = lbl_805A0EC8->s3(bytes);
    a.data = r;
    a.cap = n | 0x80000000;
    a.orig = r;
}
static inline void fr(Arr& a) {
    unsigned int mark = a.orig;
    Alloc* allocator = lbl_805A0EC8;
    allocator->cur = mark;
    if (mark == allocator->lim1) allocator->s4();
    if (!a.isUnowned())
        a.dealloc();
}

extern "C" void fn_802F7E24(Ctx* self, In* in) {
    if (((const int*)self)[0x7c / 4] != 0) {
        struct { char f; In* i; } m;
        m.f = 3;
        m.i = in;
        fn_802EFF2C(self, &m);
        return;
    }
    Obj* c = in->u1c;
    self->u7c = self->u7c + 1;
    if (c) {
        Arr a, b;
        char buf[0x20] __attribute__((aligned(16)));
        mk(a, self->u2e4);
        mk(b, self->u2e4);
        float scale = self->u68->f;
        scale = lbl_805A4540 * scale;
        in->u1c->s3(in->u24, buf, scale);
        void* p = in->u30;
        self->u54->s7(&p, buf, 1, &a, &b);
        int bsize = b.size;
        int asize = a.size;
        if (asize + bsize > 0) {
            fn_802CB04C(&a, &b);
            int count = b.size;
            void* data = (void*)b.data;
            void* table = self->u58;
            fn_802CAFC0(table, data, count);
            char* x = self->u6c;
            if (x) x += 8;
            int count2 = a.size;
            void* data2 = (void*)a.data;
            void* table2 = self->u58;
            fn_802CAEE8(table2, data2, count2, x);
        }
        fr(b);
        fr(a);
    }
    if (--self->u7c == 0 && self->u78 != 0 && ((unsigned int)(-(int)self->u84 | (int)self->u84) >> 31) == 0)
        fn_802EFE70(self);
}
