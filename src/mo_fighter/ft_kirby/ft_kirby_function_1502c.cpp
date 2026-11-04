#pragma force_active on
extern "C" {

struct Vec3f { float x, y, z; };

class ModuleA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void f15(Vec3f*, int);
};

struct BBase {
    int a;
    int b;
};

class ModuleB : public BBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void method(int);
};

class ModuleC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void f7(int);
};

class ModuleD {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void f16(int, int);
};

struct Enumeration {
    unsigned char pad0[0x0C];
    ModuleA* a;
    unsigned char pad1[0x28];
    ModuleB* b;
    unsigned char pad2[0x1C];
    ModuleC* c;
    unsigned char pad3[0x28];
    ModuleD* d;
};

struct Accesser {
    unsigned char pad[0xD8];
    Enumeration* m_enumeration;
};

extern float lbl_96_rodata_4C;
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_96_15108(Accesser*, int);

void fn_96_1502C(void*, Accesser* accesser, int param) {
    ModuleA* a = accesser->m_enumeration->a;
    Vec3f sp8;
    a->f15(fn_96_BC54(&sp8, lbl_96_rodata_4C, lbl_96_rodata_4C, lbl_96_rodata_4C), 0);
    accesser->m_enumeration->b->method(0);
    accesser->m_enumeration->c->f7(1);
    if (param != 0x12D) {
        accesser->m_enumeration->d->f16(3, 0);
    }
    fn_96_15108(accesser, param);
}

}