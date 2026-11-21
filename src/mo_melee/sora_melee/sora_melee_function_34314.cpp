#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <gr/collision/gr_collision.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_450;
extern "C" const float lbl_27_rodata_474;
extern "C" int fn_80111CB0(void*, void*);
extern "C" void fn_80040680(clSegment2D*, void*, void*, float, float);

struct Id { u32 v; };
struct PairU32 { u32 x, y; };
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_31270();
    virtual int fn_27_31C88();
    u32 pad;
    Id id;
};
struct HolderPrefix { u32 a, b; };
#define V10(n) \
    virtual void f##n##0(); virtual void f##n##1(); virtual void f##n##2(); \
    virtual void f##n##3(); virtual void f##n##4(); virtual void f##n##5(); \
    virtual void f##n##6(); virtual void f##n##7(); virtual void f##n##8(); \
    virtual void f##n##9();
class Holder : public HolderPrefix {
public:
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
    virtual void f80(); virtual void f81(); virtual void f82();
    virtual void f83(); virtual void f84(); virtual void f85();
    virtual PairU32 getPos(s32);
};
#undef V10
struct Bits { u8 hi : 1; u8 rest : 7; };
struct Info {
    PairU32 a;
    PairU32 b;
    clSegment2D seg;
    grCollisionLine* line;
    void* other;
    grCollision* col;
    s8 b74;
    Bits bits;
};
struct SchedBits { s32 a : 8; s32 b : 8; s32 c : 16; };
extern "C" Vec2f fn_27_34314(soNullable* self, Holder* arg1, s32 arg2) {
    Info info;
    Vec2f r;
    gfTaskScheduler* s = gfTaskScheduler::getInstance();
    int ready;
    if (s == 0)
        ready = 0;
    else
        ready = ((SchedBits*)s)->b >= 6;
    if (!ready) {
        Vec2f p;
        p.m_x = lbl_27_rodata_450;
        p.m_y = lbl_27_rodata_450;
        return p;
    }
    if (!self->fn_27_31C88()) {
        Vec2f p;
        p.m_x = lbl_27_rodata_450;
        p.m_y = lbl_27_rodata_450;
        return p;
    }
    int valid = 0;
    info.line = 0;
    info.other = 0;
    info.col = 0;
    info.b74 = 0;
    info.bits.hi = 0;
    int ok;
    if (self->id.v == 0xffff) {
        ok = 0;
    } else {
        Id id;
        id = self->id;
        if (fn_80111CB0(&id, &info.line) == 0) {
            ok = 0;
        } else {
            if (info.line && info.other && info.col)
                valid = 1;
            int v;
            if (valid && ((((u8*)info.other)[0x54] >> 4) & 1) &&
                ((((u8*)info.col)[0x2c] >> 7) & 1))
                v = 1;
            else
                v = 0;
            ok = v != 0;
        }
    }
    if (!ok) {
        Vec2f p;
        p.m_x = lbl_27_rodata_450;
        p.m_y = lbl_27_rodata_450;
        return p;
    }
    PairU32 point = arg1->getPos(arg2);
    info.b = point;
    info.a = point;
    info.col->getSegment(&info.seg, info.line);
    fn_80040680(&info.seg, &info.b, &info.a, lbl_27_rodata_450, lbl_27_rodata_474);
    Vec2f::copy(r, *(Vec2f*)&info.a - *(Vec2f*)&info.b);
    return r;
}