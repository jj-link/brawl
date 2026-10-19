#pragma force_active on
extern "C" {
void setFrameNode__8MuObjectFf(void*, float);
extern const float lbl_16_rodata_220;
extern const float lbl_16_rodata_128;
}

struct AnmObjChrRes {
    virtual ~AnmObjChrRes();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void SetFrame(float);
};

struct GfModelAnimation {
    char pad[0xC];
    AnmObjChrRes* m_anmObjChrRes;
};

extern "C" void fn_16_4878(void* self) {
    int field_98 = *(int*)((char*)self + 0x98);
    if (field_98 != 2) {
        void* obj = *(void**)((char*)self + 0x40);
        setFrameNode__8MuObjectFf(obj, lbl_16_rodata_220);
        GfModelAnimation* m = *(GfModelAnimation**)((char*)obj + 0x14);
        m->m_anmObjChrRes->SetFrame(lbl_16_rodata_128);
    }
}
