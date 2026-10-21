#pragma force_active on
struct Pair {
    int key;
    int value;
};

class Ctx {
public:
    virtual unsigned int v0();
    virtual int* v1(int key);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
};

extern "C" Ctx* fn_117_8A28(void*, int);

extern "C" void fn_117_8A64(void* a, int b, Pair* c) {
    Ctx* ctx = fn_117_8A28(a, b);
    if (ctx->v0() != 1 && c != 0) {
        int i = 0;
        while (true) {
            if (i >= ctx->v13()) {
                break;
            }
            Pair* p = c + i;
            int key = p->key;
            if (key < 0) {
                break;
            }
            int value = p->value;
            *ctx->v1(key) = value;
            i++;
        }
    }
}
