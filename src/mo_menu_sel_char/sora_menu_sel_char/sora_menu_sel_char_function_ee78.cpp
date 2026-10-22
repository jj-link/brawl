#pragma force_active on
class VB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float f);
    virtual void v9();
    virtual void v10();
    virtual void v11(void* a, void* b);
    virtual void v12();
    virtual void v13(void* a);
    virtual void v14();
    virtual void v15();
};

extern "C" {
extern const float lbl_10_rodata_2F0;
extern const float lbl_10_rodata_450;
void setFrameMatCol__8MuObjectFf(void*, float);
}

extern "C" void fn_10_EE78(char* self, int arg) {
    char* parent = *(char**)(self + 0x164);
    VB* obj = *(VB**)(self + 0x6c);
    obj->v13(*(void**)(parent + 0x10));
    if (arg != 0) {
        VB* obj2 = *(VB**)(self + 0x6c);
        obj2->v11(*(void**)((char*)obj2 + 0xE4), *(void**)(parent + 0x10));
        setFrameMatCol__8MuObjectFf(parent, lbl_10_rodata_2F0);
        char* f14 = *(char**)(parent + 0x14);
        (*(VB**)(f14 + 0x18))->v8(lbl_10_rodata_450);
    }
}
