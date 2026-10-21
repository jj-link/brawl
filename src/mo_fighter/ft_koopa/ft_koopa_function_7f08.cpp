#pragma force_active on
class FtObj {
public:
    virtual unsigned int f0() = 0;
    virtual int* f1(int arg) = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual int f13() = 0;
};

extern "C" FtObj* fn_102_7ECC(void*, void*);

extern "C" void fn_102_7F08(void* a, void* b, int* c) {
    FtObj* obj = fn_102_7ECC(a, b);
    if (obj->f0() == 1) return;
    if (c == 0) return;

    int i = 0;
    while (true) {
        int count = obj->f13();
        if (i >= count) break;
        int* p = c + i * 2;
        int val = *p;
        if (val < 0) break;
        int second = p[1];
        int* result = obj->f1(val);
        *result = second;
        i++;
    }
}
