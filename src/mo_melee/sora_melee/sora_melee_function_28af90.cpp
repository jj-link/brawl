#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

#define V1(n) virtual void n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)

class Pad4 { public: u32 pad; };
class Pad8 { public: u32 pad[2]; };

class Lbl71C8 : public Pad4 {
public:
    V4(a) V2(b)
    virtual int f8(void* a, int b, int c);
};
extern Lbl71C8 lbl_27_bss_71C8;

class Obj44 {
public:
    V16(a)
    virtual void f16(int a, int b);
};

class Obj0 {
public:
    V2(a)
    virtual void* f2(int a);
    virtual void f3(int a, void* b);
    V8(b)
    V4(c)
    virtual int f16();
    V1(d17)
    virtual void f18(u32 a);
    V16(e)
    V8(f)
    V4(g)
    V2(h)
    virtual void f49(void* a, int b);
};

class Sub {
public:
    V8(a)
    V1(b8)
    virtual int f9(int a);
    V4(c)
    V1(d14)
    virtual void f15(int a, void* b);
    V16(e)
    V16(f)
    V16(g)
    V4(h)
    V1(h68)
    virtual void f69(int a, int b, int c);
};

class ObjV8 : public Pad8 {
public:
    V8(a)
    V4(b)
    V1(c)
    virtual u32 f13();
    V1(d14)
    V1(e15)
    virtual void f16(void* a, u32 b);
};

struct Mid { char p0[0x70]; Obj0* q; };
struct Inner { char p0[0x44]; Obj44* o44; char p1[0xBC - 0x48]; ObjV8* obc; };
struct Outer { char p0[0xD8]; Inner* inner; };

struct Self {
    char p0[0x60];
    Outer* o60;
    char p1[0x1A4 - 0x64];
    Mid* m1A4;
    char p2[0x8D0 - 0x1A8];
    ObjV8* o8D0;
    char p3[0x8E0 - 0x8D4];
    float f8E0;
    int i8E4;
    char p4[0x3D30 - 0x8E8];
    u32 id3D30;
};

struct Rec {
    int a; u8 b; void* c; float d; u8 e;
    Rec(int a_, u8 b_, void* c_, float d_, u8 e_) : a(a_), b(b_), c(c_), d(d_), e(e_) {}
};

extern "C" int fn_27_28B340(char* self);
extern "C" int fn_27_28B4CC(char* self);
extern const float lbl_27_rodata_4610;

extern "C" int fn_27_28AF90(Self* self, u32 arg1) {
    int r;
    int v;
    u32 t;

    if ((u32)(self->id3D30 + 0x10000) == 0xFFFF) {
        return 0;
    }
    Obj0* module = (Obj0*)((char*)self + 0x2AAC);
    if (lbl_27_rodata_4610 != self->f8E0) {
        r = ((Lbl71C8*)&lbl_27_bss_71C8)->f8(self->p1 + 0x68, 0x5B75, 0);
        if (r != 0 && self->i8E4 > 0) {
            self->o60->inner->o44->f16(self->i8E4, 0);
            if (r == 2) {
                v = (self->m1A4->q->f16() == 2) ? 1 : ((Sub*)(self->p4 + 0x1EC0))->f9(3);
                if (v != 0) {
                    ((Sub*)((char*)self + 0x27A8))->f69(3, self->i8E4, 0);
                    Rec rec(0x3F, 0, self, self->f8E0, 0);
                    ((Sub*)(self->p4 + 0x1EC0))->f15(3, &rec);
                }
            }
        }
        if (arg1 & 2) {
            module->f18(0x22000003);
            if (self->m1A4->q->f16() == 5 &&
                (((Lbl71C8*)&lbl_27_bss_71C8)->f8(self->p1 + 0x68, 0x5B6C, 0) & 0x10)) {
                ((Obj0*)((char*)self + 0x3474))->f49((char*)self + 0xCC, 0);
            }
        }
    }
    self->o8D0->f16(self, self->id3D30);
    if (self->m1A4->q->f16() == 2 || self->m1A4->q->f16() == 7) {
        return 0;
    }
    if (arg1 & 0x10) {
        ((Obj0*)((char*)self + 0x2C34))->f3(6, (char*)self + 0xCC);
        return 1;
    }
    if (arg1 & 4) {
        if (fn_27_28B340((char*)self) != 0) {
            return 1;
        }
        goto done;
    }
    if (arg1 & 1) {
        if (self->m1A4->q->f16() == 5 ||
            (*(u32*)(((Obj0*)((char*)self + 0x297C))->f2(8)) & 0x4000)) {
            if (fn_27_28B340((char*)self) != 0) {
                return 1;
            }
            t = *(u32*)(((Obj0*)((char*)self + 0x297C))->f2(8));
            if (((t & 0x100000) | (t & 0xF)) != 0) {
                ((Obj0*)((char*)self + 0x3474))->f49((char*)self + 0xCC, 0);
            }
        }
        goto done;
    }
    if (arg1 & 8) {
        ObjV8* obc = self->o60->inner->obc;
        if (obc->f13() == 1 && fn_27_28B4CC((char*)self) != 0) {
            return 1;
        }
    }
done:
    return 0;
}
