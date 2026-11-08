#pragma force_active on
#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <gr/collision/gr_collision.h>
#include <mt/mt_coll2d.h>

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" u32 fn_80134534(void*, u32);
extern "C" float rsqrtf__Ff(float);
extern float lbl_27_rodata_3C0[];

struct Shape { char pad[4]; void* id; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Shape* slot1(u32);
};
struct Base { char pad[8]; };
class Self : public Base {
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
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual u64 calculate(u32, u32);
    char pad1[0x1c];
    Object_vptr_0* shapes;
};
struct QBits { u8 hi : 1; u8 rest : 7; };
struct Local {
    u32 query;
    u8 pad[4];
    Vec2f d2;
    Vec2f d1;
    union { u64 raw; Vec2f point; };
    clSegment2D segment;
    grCollisionLine* line;
    u32 unk;
    grCollision* collision;
    u8 flag;
    QBits bits;
};
extern "C" float fn_27_284F0(Self* self, u32 flags, u32 arg2) {
    Local l;
    float* k = lbl_27_rodata_3C0;
    u32 mode;
    if (flags & 1) mode = 0;
    else if (flags & 8) mode = 3;
    else if (flags & 2) mode = 1;
    else {
        mode = 0;
        if (flags & 4) mode = 2;
    }
    l.query = fn_80134534(self->shapes->slot1(arg2)->id, mode);
    l.line = 0;
    l.unk = 0;
    l.collision = 0;
    l.flag = 0;
    l.bits.hi = 0;
    if (fn_80111CB0(&l.query, &l.line) == 0) return k[1];
    l.collision->getSegment(&l.segment, l.line);
    l.raw = self->calculate(flags, arg2);
    l.d1.m_x = l.segment.m_p0Pos.m_x - l.point.m_x;
    l.d1.m_y = l.segment.m_p0Pos.m_y - l.point.m_y;
    float firstSquared = l.d1.m_x * l.d1.m_x + l.d1.m_y * l.d1.m_y;
    float firstLength;
    if ((float)(double)nw4r::math::FAbs(firstSquared) <= k[10]) firstLength = k[1];
    else firstLength = firstSquared * rsqrtf__Ff(firstSquared);
    l.d2.m_x = l.segment.m_p0Pos.m_x - l.segment.m_p1Pos.m_x;
    l.d2.m_y = l.segment.m_p0Pos.m_y - l.segment.m_p1Pos.m_y;
    float secondSquared = l.d2.m_x * l.d2.m_x + l.d2.m_y * l.d2.m_y;
    float secondLength;
    if ((float)(double)nw4r::math::FAbs(secondSquared) <= k[10]) secondLength = k[1];
    else secondLength = secondSquared * rsqrtf__Ff(secondSquared);
    if (k[1] == secondLength) return k[1];
    return firstLength / secondLength - k[11];
}