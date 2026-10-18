#pragma force_active on
typedef unsigned int u32;

extern const float lbl_41_rodata_BE0;
extern const float lbl_41_rodata_BE8;

class fnVt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, void*, float);
    virtual void v5();
    virtual void v6(int, void*, int, float);
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
    virtual void v18(u32);
};

extern "C" void fn_41_11830(char* em) {
    char* p = *(char**)(em + 0x3c);
    fnVt* m1 = *(fnVt**)(*(char**)(p + 0xd8) + 0x6c);
    m1->v6(5, p, 2, lbl_41_rodata_BE0);
    char* q = *(char**)(em + 0x3c);
    fnVt* m2 = *(fnVt**)(*(char**)(q + 0xd8) + 0x6c);
    m2->v4(5, q, lbl_41_rodata_BE8);
    fnVt* m3 = *(fnVt**)(*(char**)(*(char**)(em + 0x3c) + 0xd8) + 0x64);
    m3->v18(0x22000007);
}
