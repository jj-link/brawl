#pragma force_active on
extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
void setFrameVisible__8MuObjectFf(void* obj, float f);
extern char lbl_10_data_B20[];
extern const float lbl_10_rodata_6B8;
}

class Obj {
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
    virtual void v13(void* a);
};

extern "C" void fn_10_16E90(char* self, int a) {
    if (a == 2) {
        ((Obj*)*(void**)(self + 0x404))->v13(*(void**)(*(char**)(self + 0xd8) + 0x10));
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(*(void**)(self + 0x404), *(void**)(*(char**)(self + 0xd8) + 0x10), lbl_10_data_B20);
        setFrameVisible__8MuObjectFf(*(void**)(self + 0xd8), lbl_10_rodata_6B8);
    } else {
        ((Obj*)*(void**)(self + 0x404))->v13(*(void**)(*(char**)(self + 0xd8) + 0x10));
    }
}
