#pragma force_active on

extern char lbl_804103F8[];

class fnObj {
public:
    virtual void v0();
    virtual void v1(char* str, int a, int b);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

extern "C" void fn_802D008C(int arg0, fnObj* obj) {
    obj->v1(lbl_804103F8 + 0xF, 1, arg0);
    obj->v6();
}
