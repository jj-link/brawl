#pragma force_active on
struct VA {
    virtual void f0();
    virtual void* f1();
};

struct Pad {
    int x;
    int y;
};

struct VB : Pad {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20(int);
};

extern "C" {
void* fn_27_6F30C(void*);

void fn_27_6C9B8(char* p) {
    char* a = *(char**)(p + 0x48);
    char* r = (char*)((VA*)a)->f1();
    void* b = fn_27_6F30C(r + 0x1c);
    char* c = *(char**)((char*)b + 0x44);
    char* d = *(char**)(c + 0xd8);
    char* e = *(char**)(d + 0x38);
    ((VB*)e)->f20(0);
}
}
