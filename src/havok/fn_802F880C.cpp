#pragma force_active on
#include <types.h>
extern "C" int __cntlzw(unsigned int);
struct Key {
    virtual void slot0(int);
    char pad4[0x1C];
    u16 f20;
    char pad22[0x1A];
    int f3C;
    s8 invalid() { return (s8)((unsigned int)__cntlzw(f20 ^ 0xFFFF) >> 5); }
    int test() { int ret = 0; if (!invalid() && f3C == 0) ret = 1; return ret; }
};
struct Arg1 {
    char pad0[0x8];
    int f8;
    char pad0C[0x4C];
    Key* f58;
};
struct Arg0 {
    char pad0[0xB4];
    s8 fB4;
    int test(Key* key) { int ret = 0; if (key->test() && fB4) ret = 1; return ret; }
};
extern "C" void fn_802E9E74(Key*, Arg1*);
extern "C" void fn_802F8DE8(Arg0*, Key*);
extern "C" void fn_802F880C(Arg0* arg0, Arg1* arg1) {
    Key* key = arg1->f58;
    arg1->f8 = 0;
    fn_802E9E74(key, arg1);
    int outer = 0;
    int inner = 0;
    if (!key->invalid() && key->f3C == 0) inner = 1;
    if (inner && arg0->fB4) outer = 1;
    if (outer) {
        fn_802F8DE8(arg0, key);
        if (key != 0) key->slot0(1);
    }
}
