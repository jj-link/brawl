#pragma force_active on
extern "C" void fn_27_1DACB8(void* fighter);
extern "C" const float lbl_27_rodata_7568[];

class Work {
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
    virtual void setFloat(float value, unsigned int index);
};

extern "C" void fn_27_323AFC(char* fighter) {
    Work* work = *(Work**)(*(char**)(*(char**)(fighter + 0x60) + 0xd8) + 0x64);
    work->setFloat(lbl_27_rodata_7568[0], 0x11000001);
    fn_27_1DACB8(fighter);
}
