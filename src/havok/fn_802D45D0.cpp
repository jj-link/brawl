#pragma force_active on

extern char lbl_80410778[];

class Class_80487550 {
public:
    virtual void fn_802D2670();
    virtual void fn_802D45D0(char*, int, int);
    virtual void fn_802D45C8();
    virtual void fn_802D3478();
    virtual void fn_802D0890();
    virtual void fn_802D3B30();
    virtual void fn_802D0914();
};

extern "C" void fn_802D45D0(int arg0, Class_80487550* obj) {
    obj->fn_802D45D0(lbl_80410778 + 0x10, 1, arg0);
    obj->fn_802D0914();
}
