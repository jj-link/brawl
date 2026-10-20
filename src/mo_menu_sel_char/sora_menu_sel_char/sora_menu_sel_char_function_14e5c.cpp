#pragma force_active on
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

extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
extern char lbl_10_data_B20[];

extern "C" void fn_10_14E5C(char* self, int flag) {
    ((Obj*)*(void**)(self + 0x404))->v13(*(void**)(*(char**)(self + 0xd4) + 0x10));
    if (flag != 0) {
        ((Obj*)*(void**)(self + 0x404))->v13(*(void**)(*(char**)(self + 0xd4) + 0x10));
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(*(void**)(self + 0x404), *(void**)(*(char**)(self + 0xd4) + 0x10), lbl_10_data_B20);
    }
}
