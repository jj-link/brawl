#pragma force_active on

struct Pair {
    int key;
    int value;
};

class Ctx {
public:
    virtual unsigned int f0();
    virtual int* f1(int key);
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
    virtual int f13();
};

extern "C" Ctx* fn_91_9450(int a, int b);

extern "C" void fn_91_948C(int a, int b, Pair* c) {
    Ctx* ctx = fn_91_9450(a, b);
    if (ctx->f0() != 1 && c != 0) {
        int i = 0;
        while (true) {
            if (i >= ctx->f13()) {
                break;
            }
            Pair* p = c + i;
            int key = p->key;
            if (key < 0) {
                break;
            }
            int value = p->value;
            *ctx->f1(key) = value;
            i++;
        }
    }
}