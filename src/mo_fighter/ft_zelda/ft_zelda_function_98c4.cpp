#pragma force_active on
struct Pair { int key; int value; };
class Class_71E8 {
public:
    virtual unsigned int fn_104_E064();
    virtual int* fn_104_DFB4(int);
    virtual void fn_104_E060();
    virtual void fn_104_E05C();
    virtual void fn_104_E058();
    virtual void fn_104_E054();
    virtual void fn_104_E050();
    virtual void fn_104_E04C();
    virtual void fn_104_E048();
    virtual void fn_104_E040();
    virtual void fn_104_E03C();
    virtual void fn_104_E034();
    virtual void fn_104_E030();
    virtual int fn_104_E028();
};
extern "C" Class_71E8* fn_104_9888(void*, int);
extern "C" void fn_104_98C4(void* a, int b, Pair* c) {
    Class_71E8* ctx = fn_104_9888(a, b);
    if (ctx->fn_104_E064() != 1 && c != 0) {
        int i = 0;
        while (true) {
            if (i >= ctx->fn_104_E028()) break;
            Pair* p = c + i;
            int key = p->key;
            if (key < 0) break;
            int value = p->value;
            *ctx->fn_104_DFB4(key) = value;
            i++;
        }
    }
}