#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_47_1750(void*, const char*);
void __ct__14snd3DGeneratorFv(void*);
extern char lbl_47_data_2BF8[];
extern const float lbl_47_rodata_F0;
extern const float lbl_47_rodata_F4;
}

class Obj {
public:
    char pad[0x3c];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42(void*);
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78(void*);
};

struct Layout {
    char pad[0x158];
    int a, b, c;
    float d;
    unsigned char e, f, g, pad16b;
    float h, i;
};

extern "C" void* fn_47_AD50(void* a, void* b, const char* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x17c, 0xf);
    if (obj) {
        fn_47_1750(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_47_data_2BF8;
        __ct__14snd3DGeneratorFv((char*)obj + 0x174);
        ((Layout*)obj)->a = 0;
        ((Layout*)obj)->b = 0;
        ((Layout*)obj)->c = 0;
        ((Layout*)obj)->d = lbl_47_rodata_F0;
        ((Layout*)obj)->e = 0;
        ((Layout*)obj)->f = 2;
        ((Layout*)obj)->g = 1;
        ((Layout*)obj)->h = lbl_47_rodata_F4;
        ((Layout*)obj)->i = lbl_47_rodata_F4;
    }
    if (obj) {
        ((Obj*)obj)->m42(a);
        ((Obj*)obj)->m78(b);
    }
    return obj;
}
