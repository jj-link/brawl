#pragma force_active on

extern char lbl_80410FB0[];

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

extern "C" void fn_802D71A8(int arg0, fnObj* obj) {
    obj->v1(lbl_80410FB0 + 0x10, 1, arg0);
    obj->v6();
}
