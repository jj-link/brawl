#include <types.h>
#pragma force_active on

struct Value { int a[3]; };
struct Object;
extern "C" void fn_27_71948(Value* result, const Object* object, int index);
extern "C" char lbl_27_data_8390[];

struct Sub { virtual void fill(short* a, void* b); };
struct Src { virtual void v0(); virtual void v1(); virtual Object* getAt(int i); virtual void v3(); virtual int getCount(); };
struct Owner { char pad[0x20]; Src* src; };
struct LV { virtual void v0(); virtual Object** at(int i); };

extern "C" bool fn_27_719C0(Owner* self, const short* id, int idx) {
    short v = *id;
    if (v == -1) {
        int n = self->src->getCount();
        for (int i = 0; i < n; i++) {
            Value r;
            fn_27_71948(&r, self->src->getAt(i), idx);
            if (r.a[1] == 0) {
                return false;
            }
        }
    } else {
        short s = v;
        struct L { void** vt; char* d; unsigned bits; char pad[0x50]; } l;
        l.vt = (void**)lbl_27_data_8390;
        l.d = lbl_27_data_8390 + 0x48;
        l.bits &= 0x1FFF;
        ((Sub*)((char*)self->src + 0xc))->fill(&s, &l);
        int n = ((int)((l.bits << 12) & 0xFE000000)) >> 26;
        for (int i = 0; i < n; i++) {
            Object** o = ((LV*)&l)->at(i);
            Value r;
            fn_27_71948(&r, *o, idx);
            if (r.a[1] == 0) {
                return false;
            }
        }
    }
    return true;
}
