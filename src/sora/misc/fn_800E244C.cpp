#pragma force_active on
#include <types.h>
#include <mu/mu_object.h>

class CtorBase {
public:
    virtual void slot0();
    virtual void slot1();
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
    virtual void ctor(void*);
};

extern "C" {
int fn_800B63B8(MuObject*);
void fn_800E25A8(void*);
void fn_800E34C8(void*);
void fn_800E4638(void*);
}

extern CtorBase* lbl_805A02DC;
extern CtorBase* lbl_805A02E0;
extern void* lbl_80408880[];

extern "C" void fn_800E244C(void* self_v) {
    char* self = (char*)self_v;
    int idx;
    s32 cnt;
    MuObject* obj;

    int c = *(int*)(self + 0x5D0);
    *(int*)(self + 0x5D0) = c + 1;
    fn_800E25A8(self_v);

    int a = *(int*)(self + 0x10);
    if ((unsigned)(a - 1) <= 1) {
        u32 x = (u32)((2 - a) | (a - 2));
        int off = (x >> 29) & 4;
        obj = *(MuObject**)(self + 0x28 + off);
        if (fn_800B63B8(obj) != 0) {
            CtorBase* base = lbl_805A02DC;
            MuObject* o = *(MuObject**)((char*)obj + 0x10);
            base->ctor(o);
            *(int*)(self + 0x10) = 0;
        }
    }

    fn_800E34C8(self_v);

    char* p = self;
    for (cnt = 0; cnt < 5; cnt++) {
        idx = *(int*)(p + 0x214);
        void* f = lbl_80408880[idx * 2 + 1];
        if (f != 0) {
            int r = ((int (*)(int, void*))f)(cnt, self_v);
            *(int*)(p + 0x214) = r;
        }
        int idx2 = *(int*)(p + 0x214);
        if (idx != idx2) {
            void* g = lbl_80408880[idx2 * 2];
            if (g != 0) {
                ((void (*)(int, void*))g)(cnt, self_v);
            }
        }
        p += 4;
    }

    fn_800E4638(self_v);

    int n = *(int*)(self + 0x554);
    if (n > 0) {
        n--;
        *(int*)(self + 0x554) = n;
        if (n <= 0) {
            char* q = *(char**)(self + 0xEC);
            *(int*)(self + 0x554) = 0;
            CtorBase* base = lbl_805A02E0;
            void* o = *(void**)(q + 0x10);
            base->ctor(o);
        }
    }
}
