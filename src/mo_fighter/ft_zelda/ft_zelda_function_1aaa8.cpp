#pragma force_active on
struct Pair { int key; int value; };
class Object_vptr_0 {
public:
    virtual unsigned int slot0();
    virtual int* slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
};
extern "C" Object_vptr_0* fn_104_1AA6C(void*, int);
extern "C" void fn_104_1AAA8(void* a, int b, Pair* c) {
    Object_vptr_0* ctx = fn_104_1AA6C(a, b);
    if (ctx->slot0() != 1 && c != 0) {
        int i = 0;
        while (true) {
            if (i >= ctx->slot13()) break;
            Pair* p = c + i;
            int key = p->key;
            if (key < 0) break;
            int value = p->value;
            *ctx->slot1(key) = value;
            i++;
        }
    }
}