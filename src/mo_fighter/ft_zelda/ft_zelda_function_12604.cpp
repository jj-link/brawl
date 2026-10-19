#pragma force_active on
extern "C" {
void fn_27_1DACB8(char* fighter);

struct VObj {
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
    virtual void call20(unsigned int arg);
};

void fn_104_12604(char* fighter)
{
    char* a = *(char**)(fighter + 0x60);
    char* b = *(char**)(a + 0xd8);
    VObj* obj = *(VObj**)(b + 0x64);
    obj->call20(0x22000000);
    fn_27_1DACB8(fighter);
}
}
