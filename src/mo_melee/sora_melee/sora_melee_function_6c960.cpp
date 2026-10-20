#pragma force_active on
extern "C" void* fn_27_6F30C(void* node);

class VA {
public:
    virtual void* m0();
    virtual void* m1();
};

struct Pad8 {
    int a;
    int b;
};

class VB : public Pad8 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19(int arg);
};

extern "C" void fn_27_6C960(void* self) {
    void* b = *(void**)((char*)self + 0x48);
    void* ret = ((VA*)b)->m1();
    void* p = fn_27_6F30C((char*)ret + 0x1c);
    void* q = *(void**)((char*)p + 0x44);
    void* r = *(void**)((char*)q + 0xd8);
    void* s = *(void**)((char*)r + 0x38);
    ((VB*)s)->m19(0);
}
