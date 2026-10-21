#pragma force_active on
extern "C" {
extern const char lbl_122_data_8B84[], lbl_122_data_8BB0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_3B43E4(void*, void*, int);
}

struct Base { int a; int b; };

struct RMObj : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* f4();
};

extern "C" int fn_122_E718(void* self, void* acc) {
    void* so = *(void**)((char*)acc + 0x8);
    void* so28 = *(void**)((char*)so + 0x28);
    void* enumStart = *(void**)((char*)acc + 0xD8);
    RMObj* rm = *(RMObj**)enumStart;
    void* p = rm->f4();
    void* pc = __dynamic_cast(p, 0, (const void*)lbl_122_data_8B84, (const void*)lbl_122_data_8BB0, 1);
    int resource = fn_27_14DB04(pc);
    fn_27_3B43E4(self, so28, resource);
    return 1;
}
