#pragma force_active on

extern "C" {
extern const char lbl_96_data_67C4[], lbl_96_data_67F0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_96_2F4BC(void*, int, int, float, int);
}

struct Observer {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual int m3();
};

struct Resource {
    int pad0;
    int pad1;
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void* m4();
};

struct Wrapper {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual float m9();
};

extern "C" int fn_96_BDE0(void* arg0, void* arg1) {
    char* modules = (char*)*(void**)((char*)arg1 + 0xd8);
    Observer* obs = *(Observer**)(modules + 0x14);
    int bval = (obs->m3() == 2);

    char* modules2 = (char*)*(void**)((char*)arg1 + 0xd8);
    Resource* res = *(Resource**)modules2;
    int tid = *(int*)(*(char**)((char*)arg1 + 8) + 0x28);
    Wrapper* w = *(Wrapper**)(modules2 + 0x0c);
    float fv = w->m9();

    void* ptr = res->m4();
    int r = fn_27_14DB04(__dynamic_cast(ptr, 0, lbl_96_data_67C4, lbl_96_data_67F0, short(1)));

    fn_96_2F4BC(arg0, tid, r, fv, bval);
    return 1;
}