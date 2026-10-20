#pragma force_active on
extern const char lbl_27_data_9B6C0[];
extern const char lbl_27_data_248[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int fn_27_39FA04(void*, void*);

class C7 {
public:
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int a, int b);
};

extern "C" void fn_27_3A0694(void* a, void* b) {
    void* d = __dynamic_cast(*(void**)((char*)b + 8), 0x3c, lbl_27_data_9B6C0, lbl_27_data_248, 1);
    void* p = *(void**)((char*)b + 0xd8);
    C7* obj = (C7*)*(void**)((char*)p + 0x64);
    int x = fn_27_39FA04(d, p);
    obj->m7(x, 0x10000006);
}
