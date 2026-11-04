#pragma force_active on
class Vt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int);
    virtual void v5(int, int);
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
    virtual int v16();
    virtual void v17();
    virtual float v18(int);
};

struct Pad8 {
    int a;
    int b;
};

class Vt38 : public Pad8 {
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
    virtual void v16();
    virtual void v17();
    virtual float v18(int);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DB0E8();
extern const unsigned char lbl_114_data_7D2C[], lbl_114_data_3C7C[];
extern const float lbl_114_rodata_C0, lbl_114_rodata_C8;
}

extern "C" void fn_114_1568C(void* self, void* a2, void* a3, void* a4, void* a5) {
    fn_27_1DB0E8();
    unsigned char* o = *(unsigned char**)((unsigned char*)self + 0x60);
    o = *(unsigned char**)(o + 0xd8);
    Vt* st = *(Vt**)(o + 0x70);
    if (st->v16() == 1) {
        unsigned char* f = (unsigned char*)__dynamic_cast(*(void**)((unsigned char*)a5 + 8), 0x3c,
                                                          lbl_114_data_7D2C, lbl_114_data_3C7C, 1);
        float* param = *(float**)(f + 0x23ac);
        Vt38* t = *(Vt38**)(*(unsigned char**)((unsigned char*)a5 + 0xd8) + 0x38);
        float dmg = t->v18(0);
        Vt* w = *(Vt**)(*(unsigned char**)((unsigned char*)a5 + 0xd8) + 0x64);
        float v = (float)w->v4(0x10000004) - dmg * param[5];
        if (v < lbl_114_rodata_C8) {
            v = lbl_114_rodata_C0;
        }
        Vt* w2 = *(Vt**)(*(unsigned char**)((unsigned char*)a5 + 0xd8) + 0x64);
        w2->v5((int)v, 0x10000004);
    }
}
