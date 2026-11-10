#include <types.h>
#pragma force_active on

extern "C" {
void fn_801A76EC(void* self, void* src);
void fn_801A7750(void* self, void* p);
void fn_801A7A24(void* self, f32 a, f32 b, f32 c, f32 d);
void fn_801A7A5C(void* self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern f32 lbl_805A32E8;
}

struct Result {
    u32 flags;
    s32 type;
    f32 vec8[3];
    f32 v14, v18, v1C;
    f32 v20, v24, v28, v2C, v30;
};

struct Frame {
    f32 f8, fC, f10;
    f32 f14, f18, f1C;
    s32 i20;
    f32 f24, f28, f2C, f30, f34, f38, f3C, f40, f44, f48;
    u8 buf[0x3C];
};

class Obj {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32();
    virtual Result* getResult(void* buf);
};

extern "C" s32 fn_8019D204(Obj* self, void* arg1) {
    Frame fr;
    Result* r = self->getResult(fr.buf);
    if (!(r->flags & 2)) {
        return 0;
    }
    switch (r->type) {
    case 0:
        fn_801A7A24(arg1, r->v30, r->v14, r->v18, r->v1C);
        break;
    case 1: {
        f32 f1 = r->v30 * lbl_805A32E8;
        f32 f4 = f1 * r->v14;
        fn_801A7A5C(arg1, f1, -f1, -f4, f4, r->v18, r->v1C);
        break;
    }
    }
    switch (r->flags & 1) {
    case 0: {
        f32 c;
        f32 b;
        f32 a;
        fr.i20 = 1;
        a = r->v20;
        b = r->v24;
        c = r->v28;
        fr.f14 = a;
        fr.f18 = b;
        fr.f1C = c;
        fr.f3C = a;
        fr.f40 = b;
        fr.f44 = c;
        break;
    }
    case 1: {
        f32 a;
        f32 c;
        f32 b;
        fr.i20 = 2;
        a = r->v20;
        b = r->v24;
        c = r->v28;
        fr.f8 = a;
        fr.f30 = a;
        fr.f34 = b;
        fr.f38 = c;
        a = r->v2C;
        fr.fC = b;
        fr.f10 = c;
        fr.f48 = a;
        break;
    }
    }
    fn_801A76EC(arg1, r->vec8);
    fn_801A7750(arg1, &fr.i20);
    return 1;
}
