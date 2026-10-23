#pragma force_active on
extern "C" {
int fn_27_1922CC(void*, unsigned long);
float fn_27_192278(void*, unsigned long);
}
extern float lbl_27_rodata_8084;

struct Sub {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual float calc(void*);
};

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set1C(int, unsigned long);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setF(unsigned long, float);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void setU(unsigned long);
};

extern "C" void fn_27_3C758C(void* arg0) {
    unsigned char* r4 = *(unsigned char**)((unsigned char*)arg0 + 0xD8);
    Sub* r3 = *(Sub**)(r4 + 0xC);
    Target* t = *(Target**)(r4 + 0x64);
    float f = r3->calc(r4);
    t->setF(0x2100000C, f);
    t->setF(0x2100000D, f);
    t->setF(0x2100000E, f);
    t->set1C(fn_27_1922CC(arg0, 0x5DC0), 0x20000000);
    t->set1C(-1, 0x20000001);
    t->set1C(-1, 0x20000002);
    t->set1C(0, 0x20000003);
    t->setF(0x21000006, lbl_27_rodata_8084);
    t->setF(0x2100000B, lbl_27_rodata_8084);
    t->setF(0x21000009, lbl_27_rodata_8084);
    t->set1C(0, 0x20000004);
    t->set1C(0, 0x20000005);
    float g = fn_27_192278(arg0, 0xFB7);
    t->setF(0x21000005, g);
    t->setU(0x22000010);
}
