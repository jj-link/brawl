#pragma force_active on
#define V1(n) virtual void n##x();
#define V4(n) V1(n##a) V1(n##b) V1(n##c) V1(n##d)
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)
struct Sub {
    V4(a)
    virtual int f4(int, unsigned);
    V1(d) V1(e) V1(f)
    virtual void f8(int);
    virtual int f9(int);
    V16(g) V16(h) V16(i) V16(j) V1(k)
    virtual void f75(int, unsigned, unsigned, int, int);
    V4(l) V4(m) V1(n) V1(o) V1(p)
    virtual void f87(int);
    V4(q) V4(r) V1(s) V1(t) V1(u)
    virtual void f99(int, int, int);
};
struct Q {
    char pad[8];
    V16(a) V16(b) V4(c) V4(d) V4(e) V1(f) V1(g) V1(h)
    virtual int f47(void*);
};
struct R {
    char pad[4];
    V4(a) V1(b) V1(c)
    virtual int f6(void*, int, int);
};
struct D {
    V16(a) V4(b) V4(c) V1(d) V1(e)
    virtual void f26(float);
};
struct Self {
    char pad0[0xCC];
    char b[0x8D0 - 0xCC];
    Q* p8D0;
    char pad1[0xDB4 - 0x8D4];
    D d;
    char pad2[0x27A8 - 0xDB8];
    Sub s;
};
struct Raw { int a; int b; };
extern Raw lbl_27_bss_71C8;
extern const float lbl_27_rodata_461C;

extern "C" int fn_27_28C26C(Self* self, unsigned arg1, unsigned arg2, unsigned arg3) {
    if (arg1 + 0x10000 == 0xffff || arg2 + 0x10000 == 0xffff || arg3 + 0x10000 == 0xffff) return 0;
    self->s.f87(1);
    if (self->s.f9(3) != 0) self->s.f8(3);
    if (self->s.f4(3, arg1) == 0) return 0;
    if (self->p8D0->f47(self) != 0) {
        self->s.f75(3, arg3, arg2, 3, 1);
        if (((R*)&lbl_27_bss_71C8)->f6(self->b, 0x5b6d, 0) == 1) {
            self->d.f26(lbl_27_rodata_461C);
            self->s.f99(3, 2, 1);
        }
    }
    return 1;
}
