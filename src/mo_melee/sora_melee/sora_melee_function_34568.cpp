#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <mt/mt_vector.h>
#pragma force_active on
#pragma fp_contract off

struct Id { u32 v; };
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_31270();
    virtual int fn_27_31C88();
    u32 pad;
    Id id0;
    Id id1;
};
struct Bits { u8 hi : 1; u8 rest : 7; };
struct Ref { void* a; void* b; void* c; u8 byte; Bits bits; };
struct PairU32 { u32 x, y; };
struct SchedBits { s32 a : 8; s32 b : 8; s32 c : 16; };
extern "C" int fn_80111CB0(void*, void*);
extern "C" u64 fn_80114E9C(Ref*);
extern "C" void fn_8003DBA8(Vec2f*);
extern "C" const float lbl_27_rodata_454;

inline bool enabled(Ref& r) {
    int valid = 0;
    if (r.a && r.b && r.c) valid = 1;
    if (valid && ((((u8*)r.b)[0x54] >> 4) & 1) &&
        ((((u8*)r.c)[0x2c] >> 7) & 1))
        return true;
    return false;
}
inline bool getRef(Id& source, Ref& r, int& valid) {
    if (source.v == 0xffff) return false;
    Id id;
    id = source;
    if (fn_80111CB0(&id, &r) == 0) return false;
    if (r.a && r.b && r.c) valid = 1;
    int value;
    if (valid && ((((u8*)r.b)[0x54] >> 4) & 1) &&
        ((((u8*)r.c)[0x2c] >> 7) & 1))
        value = 1;
    else value = 0;
    return value != 0;
}

extern "C" int fn_27_34568(soNullable* self) {
    gfTaskScheduler* s = gfTaskScheduler::getInstance();
    int ready;
    if (s == 0) ready = 0;
    else ready = ((SchedBits*)s)->b >= 6;
    if (!ready) return 0;
    if (!self->fn_27_31C88()) return 0;

    int valid1 = 0;
    Ref r1;
    r1.a = 0; r1.b = 0; r1.c = 0; r1.byte = 0; r1.bits.hi = 0;
    if (!getRef(self->id1, r1, valid1)) return 0;
    int valid2 = 0;
    Ref r2;
    r2.a = 0; r2.b = 0; r2.c = 0; r2.byte = 0; r2.bits.hi = 0;
    if (!getRef(self->id0, r2, valid2)) return 0;
    if (!enabled(r2)) return 0;
    if (!enabled(r1)) return 0;

    Vec2f tmp;
    Vec2f delta;
    PairU32 tmp2;
    PairU32 tmp1;
    PairU32 p2;
    PairU32 p1;
    *(u64*)&tmp1 = fn_80114E9C(&r2);
    p1 = tmp1;
    *(u64*)&tmp2 = fn_80114E9C(&r1);
    p2 = tmp2;
    fn_8003DBA8((Vec2f*)&p1);
    fn_8003DBA8((Vec2f*)&p2);
    tmp.m_x = ((Vec2f*)&p1)->m_x - ((Vec2f*)&p2)->m_x;
    tmp.m_y = ((Vec2f*)&p1)->m_y - ((Vec2f*)&p2)->m_y;
    Vec2f::copy(delta, tmp);
    return delta.lengthSq() <= lbl_27_rodata_454;
}