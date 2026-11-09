#pragma force_active on
#pragma use_lmw_stmw on

class Class_80488EE0 {
public:
    virtual void fn_8032FA40();                        // offset 0x8
    virtual void fn_80080A64();                        // offset 0xC
    virtual int fn_8032FCB4(int);                      // offset 0x10
    virtual void fn_80330928(int, int);                // offset 0x14
    virtual void fn_8033259C();
    virtual void fn_803315A4();
    virtual void fn_80330698();
    virtual void fn_8032FF60();
    virtual void fn_803309D0();
    virtual void fn_8032FCAC();
    virtual void fn_8032FD74();
    virtual void fn_80331408();
    virtual int fn_80331494(int, int);
    char pad[8];
};

extern "C" Class_80488EE0* lbl_805A0F38;

extern "C" void fn_8033259C(Class_80488EE0* self, int arg2) {
    int temp = lbl_805A0F38->fn_8032FCB4(arg2);
    self->fn_80330928(arg2, temp);
}
