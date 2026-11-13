#pragma force_active on

typedef unsigned int u32;

struct Result {
    int pad0;
    float f4;
    float f8;
    char pad_a[0x90];
    unsigned char f9c;
};

class Obj {
public:
    virtual void v0();
    virtual Result* get(int);
    virtual void v2();
    virtual void v3();
    virtual u32 v4();
    virtual void v5();
    virtual u32 v6();
};

struct Middle {
    char pad[0x40];
    Obj* m_40;
    char pad2[0x24];
    Obj* m_68;
};

struct Outer {
    char pad[0xd8];
    Middle* m_d8;
};

struct Base8 { char pad[8]; };

class Self : public Base8 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual float f78();
    char pad2[0x30];
    Outer* m_3c;
    Obj* m_40;
    char pad3[0x50];
    float m_94;
};

struct Arg4Target {
    char pad[0x28];
    int m_28;
};

struct Arg4 {
    char pad[8];
    Arg4Target* m_8;
};

struct Arg5 {
    char pad[0xc];
    u32 m_c;
    char pad2[0x17];
    unsigned char m_27;
    char pad3;
    unsigned char m_29;
};

extern "C" {
extern int lbl_27_bss_2CBC;
void fn_27_C5EB0(int*, u32, int, int, float);

void fn_27_5EE08(Self* self, int a1, int arg2, int a3, Arg4* arg4, const Arg5* arg5, float f) {
    if (arg5->m_29 != 1) {
        float ret = self->f78();
        float t = f * self->m_94;
        float val = t * ret;
        fn_27_C5EB0(&lbl_27_bss_2CBC, arg5->m_c, arg4->m_8->m_28, 0, val);

        if (self->m_3c->m_d8->m_68->v4() != 1) {
            Result* res = self->m_40->get(arg2);
            res->f4 += val;
        }
        Result* res2 = self->m_40->get(arg2);
        if (val > res2->f8) {
            Result* res3 = self->m_40->get(arg2);
            res3->f8 = val;
        }
        if (arg5->m_27 == 1) {
            u32 id = self->m_3c->m_d8->m_40->v6();
            if (id == arg5->m_c) {
                Result* res4 = self->m_40->get(arg2);
                res4->f9c = 1;
            }
        }
    }
}
}
