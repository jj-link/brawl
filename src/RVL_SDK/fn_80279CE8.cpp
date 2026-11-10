#include <types.h>
#pragma force_active on

extern "C" void fn_801EC41C(void* in, void* out);
extern "C" void fn_801ECD70(void* mtx, void* in, void* out);
extern "C" void fn_80182A10(void* out, void* obj, int idx);
extern float lbl_805A3B70;

class Obj28 {
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
    virtual void slot13();
    virtual void slot14();
    virtual int slot15();
};

struct Mtx {
    float m[12];
};

struct Outer {
    char pad[0x28];
    Obj28* a;
    char* b;
};

extern "C" s32 fn_80279CE8(void* arg0, f32 farg0, f32 farg1) {
    Outer* self = (Outer*)arg0;
    if (self->a == 0) {
        return 0;
    }
    int r = self->a->slot15();
    if (r == 0) {
        return 0;
    }
    Mtx mtx;
    float in[3];
    float buf[8];
    fn_801EC41C((char*)self->b + 0x84, &mtx);
    in[0] = farg0;
    in[1] = farg1;
    in[2] = lbl_805A3B70;
    fn_801ECD70(&mtx, in, &buf[4]);
    fn_80182A10(buf, self->b, r);
    if (buf[0] <= buf[4] && buf[4] <= buf[2] && buf[3] <= buf[5] && buf[5] <= buf[1]) {
        return 1;
    }
    return 0;
}
