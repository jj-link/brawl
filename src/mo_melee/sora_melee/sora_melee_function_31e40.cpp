#include <types.h>
#include <gr/collision/gr_collision.h>
#include <so/ground/so_ground_module_impl.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma fp_contract off

struct LineId {
    union {
        u32 value;
        struct {
            u16 a;
            u16 b;
        };
    };

    LineId() { value = 0xffff; }
    LineId(const u32& v) : value(v) {}
};

class TraceState : public soNullable {
public:
    virtual void fn_27_31270();
    virtual bool fn_27_31C88();
    virtual void fn_27_31DCC();
    virtual void fn_27_31E40();

    u32 current;
    u32 next;
    u32 other;
    Vec2f target;
    Vec2f movement;
    u8 traced;
    u8 mode;
};

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 byte;
    u8 high : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), byte(0), high(0) {}

    bool valid() const {
        return line && ground && collision;
    }

    int enabled() const {
        bool v = valid();
        int result;
        if (v && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            result = 1;
        else
            result = 0;
        return result;
    }
};

extern const float lbl_27_rodata_450[];

extern "C" {
u32 fn_80111CB0(LineId*, Entry*);
s32 fn_27_319A8(TraceState*, u32*, Entry*, u32, u32, soGroundModule*, u32, float);
u32 fn_80114ABC(Entry*, Vec2f*, Entry*);
u16 fn_80111C54(grCollision*, grCollisionLine*);
void fn_80111DE4(LineId*, const Vec2f*, Vec2f*);
Vec2f fn_27_312B0(TraceState*, const Vec2f*, float);
}

#pragma inline all
inline bool loadTraceCurrent(TraceState* self, Entry* entry) {
    if (self->current == 0xffff) return false;
    LineId id(self->current);
    if (!fn_80111CB0(&id, entry)) return false;
    return entry->enabled() != 0;
}
inline u32 makeTraceId(Entry* context) {
    LineId id;
    id.a = context->collision->m_index;
    id.b = fn_80111C54(context->collision, context->line);
    return id.value;
}
inline float traceLenSq(const Vec2f& v) {
    return v.m_x*v.m_x+v.m_y*v.m_y;
}
inline float traceSqrt(float sq, const float* c) {
    return ((float)(double)nw4r::math::FAbs(sq)<=c[8]) ? c[0] : sq*rsqrtf(sq);
}
inline float traceLen(const Vec2f& v, const float* c) {
    return traceSqrt(traceLenSq(v),c);
}
inline bool traceWithin(const Vec2f& v, float size, const float* c) {
    return traceLen(v,c)<=size;
}
inline Vec2f traceCenter(TraceState* self, Vec2f pos, float t) {
    Vec2f off;
    Vec2f::copy(off,fn_27_312B0(self,&pos,t));
    Vec2f r;
    Vec2f::copy(r,self->target+off);
    return r;
}
inline float traceSize(soGroundModule* ground, const float* c) {
    clRhombus2D a,b;
    ground->getRhombus(&a,&b,0);
    Vec2f d;
    Vec2f::copy(d,b.m_downPos-a.m_downPos);
    return traceLen(d,c);
}
inline bool traceNear(TraceState* self, soPostureModule* posture, soGroundModule* ground, u32 index, float t, const float* c) {
    Vec3f p=posture->getPos();
    Vec2f initial(p.m_x,p.m_y);
    Vec2f adjusted;
    if(self->mode) adjusted=initial;
    else {
        Vec2f movement;
        Vec2f::copy(movement,ground->getDownPos(index)-ground->getCenterPos(index));
        adjusted=initial-movement;
    }
    Vec2f center;
    Vec2f::copy(center,traceCenter(self,ground->getCenterPos(index),t));
    return traceWithin(adjusted-center,traceSize(ground,c),c);
}
extern "C" int fn_27_31E40(
    TraceState* self,
    u32 a,
    u32 b,
    soPostureModule* posture,
    soGroundModule* ground,
    u32 index,
    u8 mode,
    float f1,
    float f2,
    float f3
) {
    const float* c = lbl_27_rodata_450;

    if (self->fn_27_31C88() == 1)
        return 0;

    self->mode = mode;

    Entry entry;
    if (!loadTraceCurrent(self, &entry)) {
        self->current = 0xffff;
        self->other = 0xffff;
        if (!fn_27_319A8(self, &self->current, &entry, a, b, ground, index, f2))
            return 0;
    }

    self->next = 0xffff;
    u32 open = 0;
    Entry next;
    Entry cur = entry;
    clSegment2D seg;
    cur.collision->getSegment(&seg, cur.line);

    Vec2f pos(c[0], c[0]);
    if (c[9] == f3)
        pos = seg.m_p1Pos;
    else
        pos = seg.m_p0Pos;

    if (fn_80114ABC(&cur, &pos, &next) != 1)
        goto collision_failed;

    int var_r3_2 = 0;
    int var_r5 = 0;
    int enabled = 0;

    if (next.line != 0 && next.ground != 0)
        var_r5 = 1;
    if (var_r5 != 0 && next.collision != 0)
        var_r3_2 = 1;
    if (var_r3_2 != 0 && ((next.ground->flags >> 4) & 1) &&
        ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
        enabled = 1;
    else
        enabled = 0;

    if (enabled)
        goto collision_make_id;
    open = 1;
    goto collision_done;

collision_failed:
    open = 1;
    goto collision_done;

collision_make_id:
    self->next = makeTraceId(&next);

collision_done:
    self->target = pos;
    fn_80111DE4(&LineId(self->current), &ground->getCenterPos(index), &self->movement);
    self->traced = 1;

    if (open == 1) {
        if (traceNear(self, posture, ground, index, f1, c) == true)
            return 1;
    }

    return 0;
}
