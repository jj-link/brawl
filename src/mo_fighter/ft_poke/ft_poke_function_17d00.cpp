#pragma force_active on
class FtObj {
public:
    virtual unsigned int f2() = 0;
    virtual int* f3(int key) = 0;
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual int f15() = 0;
};

struct Pair {
    int key;
    int val;
};

extern "C" FtObj* fn_116_17CC4();

extern "C" void fn_116_17D00(int a, int b, Pair* c) {
    FtObj* obj = fn_116_17CC4();
    if (obj->f2() == 1) return;
    if (c == 0) return;
    int i = 0;
    while (true) {
        int count = obj->f15();
        if (i >= count) break;
        Pair* e = &c[i];
        int key = e->key;
        if (key < 0) break;
        int second = e->val;
        int* p = obj->f3(key);
        *p = second;
        i++;
    }
}
