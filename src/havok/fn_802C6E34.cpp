#include <types.h>

#pragma force_active on
#pragma use_lmw_stmw on
#pragma fp_contract on

extern "C" int __cntlzw(unsigned int);

struct Vec4 {
    float x, y, z, w;
};

struct Shape {
    char pad[12];
    float radius;
};

struct Transform {
    char pad[48];
    Vec4 pos;
};

struct Body {
    Shape* shape;
    void* key;
    Transform* transform;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(Body*, Body*);
};

struct TimerEntry {
    char* name;
    u32 time;
    u32 unused;
};

struct Timer {
    u32 unused0;
    TimerEntry* current;
    u32 unused8;
    TimerEntry* end;
    u32 unused10[2];
};

extern Timer lbl_80532448;
extern char lbl_8040FF78[];

#define RECORD(offset)                                                        \
    {                                                                         \
        Timer* timer = &lbl_80532448;                                          \
        signed char c = (signed char)(                                         \
            ((u32)timer->end                                                   \
             << __cntlzw((u32)timer->end ^ (u32)timer->current)) >> 31);         \
        if (((u32)(-c | c) >> 31) != 0) {                                      \
            TimerEntry* entry = timer->current;                               \
            entry->name = lbl_8040FF78 + (offset);                             \
            register u32 t;                                                   \
            asm { mftb t }                                                    \
            entry->time = t;                                                  \
            timer->current = entry + 1;                                       \
        }                                                                     \
    }

inline void subtract(Vec4& out, const Vec4& a, const Vec4& b) {
    out.x = b.x - a.x;
    out.y = b.y - a.y;
    out.z = b.z - a.z;
    out.w = b.w - a.w;
}

inline float addRadii(const Shape* b, const Shape* a) {
    float radiusB = b->radius;
    float radiusA = a->radius;
    return radiusA + radiusB;
}

inline void intersect(
    Shape* a, Shape* b, Transform* ta, Transform* tb,
    Body* bodyA, Body* bodyB, Object_vptr_0* handler
) {
    __attribute__((aligned(16))) Vec4 d;
    subtract(d, ta->pos, tb->pos);
    float radius = addRadii(b, a);
    float distanceSquared = d.z * d.z + (d.x * d.x + d.y * d.y);
    if (distanceSquared < radius * radius) {
        handler->slot1(bodyA, bodyB);
    }
}

extern "C" void fn_802C6E34(
    Body* a, Body* b, void* unused, Object_vptr_0* handler
) {
    RECORD(0)

    Shape* shapeA = a->shape;
    Shape* shapeB = b->shape;
    intersect(
        shapeA, shapeB, a->transform, b->transform, a, b, handler
    );

    RECORD(15)
}
