#pragma force_active on

struct Pair {
    int key;
    int value;
};

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

extern "C" FtObj* fn_106_6FE4(int a, int b, Pair* c);

extern "C" void fn_106_7020(int a, int b, Pair* c) {
    FtObj* obj = fn_106_6FE4(a, b, c);
    if (obj->f0() == 1) return;
    if (c == 0) return;

    int i = 0;
    while (true) {
        int count = obj->f13();
        if (i >= count) break;

        Pair* p = c + i;
        int key = p->key;
        if (key < 0) break;

        int value = p->value;
        int* result = obj->f1(key);
        *result = value;
        i++;
    }
}
