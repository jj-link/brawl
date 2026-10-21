#pragma force_active on

extern "C" void fn_27_12BAF8();
extern "C" void fn_27_357D00(void* a, void* b, int c);
extern "C" char lbl_27_bss_8094[];
extern const float lbl_110_rodata_1D0;

class FtObj {
public:
    virtual ~FtObj();
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
    virtual void setFloat(float, unsigned long);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void setInt(unsigned long);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(int);
};

extern "C" void fn_110_1EFCC(char* self, int param) {
    fn_27_12BAF8();
    char* base = *(char**)(*(char**)(self + 0x60) + 0xd8);
    FtObj* obj = *(FtObj**)(base + 0x64);
    obj->setFloat(lbl_110_rodata_1D0, 0x11000013);
    obj->setInt(0x1200003D);
    base = *(char**)(*(char**)(self + 0x60) + 0xd8);
    FtObj* obj2 = *(FtObj**)(base + 0x20);
    obj2->v30(0);
    fn_27_357D00(lbl_27_bss_8094, *(void**)(self + 0x60), param);
}
