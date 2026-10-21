#pragma force_active on
struct Pair {
    int key;
    int value;
};

class Obj {
public:
    virtual unsigned int f2();
    virtual int* f3(int key);
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
    virtual int f15();
};

extern "C" Obj* fn_118_8A48();

extern "C" void fn_118_8A84(int a, int b, Pair* pairs) {
    Obj* obj = fn_118_8A48();
    if (obj->f2() == 1) return;
    if (pairs == 0) return;

    int i = 0;
    while (1) {
        if (i >= obj->f15()) break;
        Pair* p = pairs + i;
        int key = pairs[i].key;
        if (key < 0) break;
        int value = p->value;
        *obj->f3(key) = value;
        i++;
    }
}
