#pragma force_active on
extern char lbl_8041037C[];

class Class_80487388 {
public:
    virtual void fn_802CD8B8();
    virtual void fn_802CD950(char*, int, int);
    virtual void fn_802CD9B0();
    virtual void fn_802CD9DC();
    virtual void fn_802D0890();
    virtual void fn_802CE094();
    virtual void fn_802D0914();
};

extern "C" void fn_802CD950(int arg0, Class_80487388* obj) {
    obj->fn_802CD950(lbl_8041037C, 1, arg0);
    obj->fn_802D0914();
}
