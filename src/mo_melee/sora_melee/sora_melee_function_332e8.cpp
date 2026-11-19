#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <gr/collision/gr_collision.h>
#include <so/ground/so_ground_module_impl.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma fp_contract off
#pragma inline all

extern const float lbl_27_rodata_450;
extern const float lbl_27_rodata_470;

struct TraceState : soGroundTracer {
    u32 current;
    u32 next;
    u32 previous;
    Vec2f position;
    Vec2f movement;
    u8 flag24;
    u8 flag25;
};

struct CollisionContext {
    grCollisionLine* line;
    grCollisionJoint* joint;
    grCollision* collision;
    u8 byte;
    u8 high : 1;
    u8 rest : 7;
    CollisionContext() {
        line = 0;
        joint = 0;
        collision = 0;
        byte = 0;
        high = 0;
    }
    bool valid() const { return line && joint && collision; }
    int enabled() const {
        if (valid() && joint->m_0x54_4 &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            return 1;
        return 0;
    }
};

extern "C" int fn_27_319A8(TraceState*, u32*, CollisionContext*, u32, u32, soGroundModule*, u32, float);
extern "C" int fn_80111CB0(u32*, CollisionContext*);
extern "C" int fn_80114F30(CollisionContext*, Vec2f*);
extern "C" Vec2f fn_27_312B0(TraceState*, const Vec2f*, float);
extern "C" Vec2f fn_80114DAC(CollisionContext*, Vec2f*);
extern "C" u32 fn_80114ABC(CollisionContext*, Vec2f*, CollisionContext*);
extern "C" u16 fn_80111C54(grCollision*, grCollisionLine*);
extern "C" void fn_80111DE4(u32*, Vec2f*, Vec2f*);

static inline void updateMovement(TraceState* self, Vec2f center, u32& id) {
    id = self->current;
    fn_80111DE4(&id, &center, &self->movement);
}

struct LineId { u32 v; };
static inline bool loadCurrent(TraceState* self, CollisionContext* work) {
    if (self->current == 0xffff) return false;
    LineId local;
    local = *(LineId*)&self->current;
    if (!fn_80111CB0(&local.v, work)) return false;
    return work->enabled() != 0;
}
static inline bool loadNext(TraceState* self, CollisionContext* work) {
    if (self->next == 0xffff) return false;
    LineId local;
    local = *(LineId*)&self->next;
    if (!fn_80111CB0(&local.v, work)) return false;
    return work->enabled() != 0;
}
static inline u32 makeId(CollisionContext* context) {
    union { u32 id; struct { u16 collision, line; } parts; } id;
    id.id = 0xffff;
    id.parts.collision = context->collision->m_index;
    id.parts.line = fn_80111C54(context->collision, context->line);
    return id.id;
}
static inline float lenSq(const Vec2f& v) {
    return v.m_x * v.m_x + v.m_y * v.m_y;
}
static inline float sqrtSafe(float square) {
    return ((float)(double)nw4r::ut::Abs(square) <= lbl_27_rodata_470)
        ? lbl_27_rodata_450 : square * rsqrtf(square);
}
static inline float length(const Vec2f& v) {
    return sqrtSafe(lenSq(v));
}
static inline Vec2f calcCenter(TraceState* self, Vec2f pos, float value) {
    Vec2f off;
    Vec2f::copy(off, fn_27_312B0(self, &pos, value));
    Vec2f result;
    Vec2f::copy(result, self->position + off);
    return result;
}
static inline float getSize(soGroundModule* ground) {
    clRhombus2D current, old;
    ground->getRhombus(&current, &old, 0);
    Vec2f d;
    Vec2f::copy(d, old.m_downPos - current.m_downPos);
    return length(d);
}
static inline bool isWithin(const Vec2f& v, float size) {
    return length(v) <= size;
}
static inline bool arrived(TraceState* self, soPostureModule* posture, soGroundModule* ground, u32 index, float value) {
    Vec3f pos3 = posture->getPos();
    Vec2f pos(pos3.m_x, pos3.m_y);
    Vec2f previous;
    if (self->flag25) previous = pos;
    else {
        Vec2f movement;
        Vec2f::copy(movement, ground->getDownPos(index) - ground->getCenterPos(index));
        previous = pos - movement;
    }
    Vec2f center;
    Vec2f::copy(center, calcCenter(self, ground->getCenterPos(index), value));
    return isWithin(previous - center, getSize(ground));
}

extern "C" int fn_27_332E8(TraceState* self, u32 line, u32 arg, soPostureModule* posture, soGroundModule* ground, u32 index, float value, float amount) {
    gfTaskScheduler* scheduler = gfTaskScheduler::getInstance();
    bool active;
    if (scheduler == 0) active = false;
    else active = (s32)((*(u32*)scheduler << 8) & 0xff800000) >> 24 >= 6;
    if (!active) return 0;
    if (!self->isTraced()) return 0;
    u32 failed = 0;
    CollisionContext work;
    if (line) {
        u32 id = 0xffff;
        if (!fn_27_319A8(self, &id, &work, line, arg, ground, index, amount)) return 0;
        CollisionContext oldWork;
        if (!loadCurrent(self, &oldWork)) return 0;
        int side = fn_80114F30(&oldWork, &self->position);
        clSegment2D segment;
        work.collision->getSegment(&segment, work.line);
        if (!side) self->position = segment.m_p0Pos;
        else self->position = segment.m_p1Pos;
        self->previous = self->current;
        self->current = id;
    } else {
        if (loadNext(self, &work) == 1) {
            self->previous = self->current;
            self->current = self->next;
        } else failed = 1;
        if (failed == 1) {
            if (arrived(self, posture, ground, index, value) == 1) return 1;
            return 0;
        }
    }
    if (!loadCurrent(self, &work)) return 0;
    self->next = 0xffff;
    u32 movementId;
    CollisionContext nextWork;
    CollisionContext copy = work;
    Vec2f point;
    Vec2f::copy(point, self->position);
    point = fn_80114DAC(&copy, &point);
    if (fn_80114ABC(&copy, &point, &nextWork) == 1) {
        bool valid = nextWork.line && nextWork.joint && nextWork.collision;
        if (valid && nextWork.enabled()) goto next_valid;
        failed = 1;
        goto next_done;
    }
    failed = 1;
    goto next_done;
next_valid:
    self->next = makeId(&nextWork);
next_done:
    self->position = point;
    updateMovement(self, ground->getCenterPos(index), movementId);
    if (failed == 1) {
        if (arrived(self, posture, ground, index, value) == 1) return 1;
    }
    return 0;
}