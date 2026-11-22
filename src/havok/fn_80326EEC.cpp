#include <types.h>
#pragma force_active on
#pragma fp_contract on

extern "C" int __cntlzw(unsigned int);
extern "C" void fn_80313080(void);
extern "C" void fn_80313084(void);
extern "C" void fn_802CB04C(void*, void*);
extern "C" void fn_802EFFA8(void*, void*);
extern "C" void fn_802EFFAC(void*, void*);
extern "C" void fn_802CAFC0(void*, void*, int);
extern "C" void fn_802CAEE8(void*, void*, int, void*);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

struct TimerEntry {
    const char* name;
    unsigned int time;
    unsigned int unused;
};

struct Timer {
    unsigned int unused;
    TimerEntry* current;
    unsigned int unused2;
    TimerEntry* end;
    TimerEntry* getEnd() const { return end; }
    TimerEntry* getCurrent() const { return current; }
};

static inline unsigned int xorValues(unsigned int a, unsigned int b) { return b ^ a; }
extern Timer lbl_80532448;
extern char lbl_80414580[];
extern const float lbl_805A4800;
extern const float lbl_805A4810;

struct BodyData;
struct Bounds;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* slot3(unsigned int);
    virtual void slot4(void*);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(void*, void*, int, void*, void*);

    char pad04[0x0c];
    void* current;
    void* unused14;
    void* begin;
    void* end;
};

class Shape {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(BodyData*, Bounds*, float);
};

extern Object_vptr_0* lbl_805A0EC8;

struct MemoryState {
    int unused;
    int failed;
    int capacity;
    char pad0c[8];
    int used;
    char pad18[0x10];
    int reserved;
};

extern MemoryState* lbl_805A0EB8;

static inline void* allocate(unsigned int size)
{
    Object_vptr_0* heap = lbl_805A0EC8;
    char* p = (char*)heap->current;
    char* next = p + ((size + 16) & ~15);
    if (next <= heap->end)
        heap->current = next;
    else
        p = (char*)heap->slot3((size + 16) & ~15);
    return p;
}

static inline void release(void* p);

class Class_802E89D8 {
public:
    Class_802E89D8() {}
    ~Class_802E89D8() { if (!isUnowned()) dealloc(); }

    void* data;
    int size;
    unsigned int capacity;
    int getSize() const { return size; }
    unsigned int isUnowned() const { return capacity & 0x80000000; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity << 3, 0x15); }
};

class Class_802E8A64 : public Class_802E89D8 {
public:
    Class_802E8A64(int n) {
        data = 0;
        size = 0;
        capacity = 0x80000000;
        data = allocate(n * 8);
        capacity = n | 0x80000000;
        saved = data;
    }
    ~Class_802E8A64() { release(saved); }

    void* saved;
};

struct Bounds {
    float min[4];
    float max[4];
};

struct BodyData {
    char pad00[0x40];
    float previous[4];
    float position[4];
    char pad60[0x3c];
    float scale;
    float radius;
};

struct Body {
    char pad00[0x1c];
    Shape* shape;
    char pad20[4];
    BodyData* data;
    char pad28[8];
    char object[0x28];
    void* owner;
};

struct Params {
    char pad00[8];
    float value;
    float getValue() const { return value; }
};

struct World {
    char pad00[0x54];
    Object_vptr_0* broadphase;
    void* collision;
    char pad5c[0x0c];
    Params* params;
    char* extra;
    char pad70[0x278];
    int capacity;
};

#define RECORD(offset) { \
    Timer* timer = &lbl_80532448; \
    signed char c = (signed char)(((unsigned int)timer->end << \
        __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31); \
    if (((unsigned int)(-c | c) >> 31) != 0) { \
        TimerEntry* entry = timer->current; \
        entry->name = lbl_80414580 + (offset); \
        register unsigned int t; \
        asm { mftb t } \
        entry->time = t; \
        timer->current = entry + 1; \
    } \
}

static inline void release(void* p)
{
    Object_vptr_0* heap = lbl_805A0EC8;
    heap->current = p;
    if (p == heap->begin)
        heap->slot4(p);
}

extern "C" void fn_80326EEC(void* self, Body** bodies, int count, World* world)
{
    if (count != 0) {
        {
            Timer* timer = &lbl_80532448;
            signed char c = (signed char)(((unsigned int)timer->end <<
                __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31);
            if (((unsigned int)(-c | c) >> 31) != 0) {
                TimerEntry* entry = timer->current;
                entry->name = lbl_80414580 + 0x3a;
                *(const char**)((char*)entry + 0x0c) = lbl_80414580 + 0x47;
                register unsigned int t;
                asm { mftb t }
                entry->time = t;
                timer->current = (TimerEntry*)((char*)entry + 0x10);
            }
        }

        int capacity0 = world->capacity;
        Class_802E8A64 local0(capacity0);

        int capacity1 = world->capacity;
        Class_802E8A64 local1(capacity1);

        Bounds* bounds = (Bounds*)allocate(count * sizeof(Bounds));
        void** objects = (void**)allocate(count * sizeof(void*));
        float zero;
        float margin = lbl_805A4810 * world->params->getValue();

        {
            Timer* timer = &lbl_80532448;
            signed char c = (signed char)(((unsigned int)timer->getEnd() <<
                __cntlzw(xorValues((unsigned int)timer->getCurrent(), (unsigned int)timer->getEnd()))) >> 31);
            if (((unsigned int)(-c | c) >> 31) != 0) {
                TimerEntry* entry = timer->getCurrent();
                entry->name = lbl_80414580 + 0x51;
                register unsigned int t;
                asm { mftb t }
                entry->time = t;
                timer->current = entry + 1;
            }
        }

        zero = lbl_805A4800;
        BodyData* data;
        Body** body = bodies;
        Bounds* out = bounds;
        void** object = objects;
        for (int i = count - 1; i >= 0; --i) {
            Body* b = *body;
            data = b->data;
            float shapeScale = data->radius * data->scale + margin;
            *object = b->object;

            b->shape->slot3(b->data, out, shapeScale);

            __attribute__((aligned(16))) float radii[4] = {
                data->radius + margin, data->radius + margin,
                data->radius + margin, data->radius + margin
            };
            __attribute__((aligned(16))) float upper[4];
            __attribute__((aligned(16))) float lower[4];
            __attribute__((aligned(16))) float delta[4];

            upper[0] = data->position[0] + radii[0];
            upper[1] = data->position[1] + radii[1];
            upper[2] = data->position[2] + radii[2];
            upper[3] = data->position[3] + radii[3];
            lower[0] = data->position[0] - radii[0];
            lower[1] = data->position[1] - radii[1];
            lower[2] = data->position[2] - radii[2];
            lower[3] = data->position[3] - radii[3];

            out->min[0] = out->min[0] > lower[0] ? out->min[0] : lower[0];
            out->min[1] = out->min[1] > lower[1] ? out->min[1] : lower[1];
            out->min[2] = out->min[2] > lower[2] ? out->min[2] : lower[2];
            out->min[3] = out->min[3] > lower[3] ? out->min[3] : lower[3];
            out->max[0] = out->max[0] < upper[0] ? out->max[0] : upper[0];
            out->max[1] = out->max[1] < upper[1] ? out->max[1] : upper[1];
            out->max[2] = out->max[2] < upper[2] ? out->max[2] : upper[2];
            out->max[3] = out->max[3] < upper[3] ? out->max[3] : upper[3];

            delta[0] = data->previous[0] - data->position[0];
            delta[1] = data->previous[1] - data->position[1];
            delta[2] = data->previous[2] - data->position[2];
            delta[3] = data->previous[3] - data->position[3];

            __attribute__((aligned(16))) float zeros[4];
            zeros[3] = zero;
            zeros[2] = zero;
            zeros[1] = zero;
            zeros[0] = zero;
            __attribute__((aligned(16))) float lowDelta[4];
            __attribute__((aligned(16))) float highDelta[4];
            lowDelta[0] = zeros[0] < delta[0] ? zeros[0] : delta[0];
            lowDelta[1] = zeros[1] < delta[1] ? zeros[1] : delta[1];
            lowDelta[2] = zeros[2] < delta[2] ? zeros[2] : delta[2];
            lowDelta[3] = zeros[3] < delta[3] ? zeros[3] : delta[3];
            highDelta[0] = zeros[0] > delta[0] ? zeros[0] : delta[0];
            highDelta[1] = zeros[1] > delta[1] ? zeros[1] : delta[1];
            highDelta[2] = zeros[2] > delta[2] ? zeros[2] : delta[2];
            highDelta[3] = zeros[3] > delta[3] ? zeros[3] : delta[3];

            out->min[0] += lowDelta[0];
            out->min[1] += lowDelta[1];
            out->min[2] += lowDelta[2];
            out->min[3] += lowDelta[3];
            out->max[0] += highDelta[0];
            out->max[1] += highDelta[1];
            out->max[2] += highDelta[2];
            out->max[3] += highDelta[3];

            ++object;
            ++body;
            ++out;
        }

        RECORD(0x5d)

        if (world->broadphase->current)
            fn_80313080();
        world->broadphase->slot7(objects, bounds, count, &local0, &local1);
        if (world->broadphase->current)
            fn_80313084();

        release(objects);
        release(bounds);

        int total = local0.getSize() + local1.getSize();
        if (total > 0) {
            RECORD(0x6a)
            fn_802CB04C(&local0, &local1);
            RECORD(0x76)

            fn_802EFFA8(world, bodies[0]->owner);
            int collisionSize = local1.size;
            void* collisionData = local1.data;
            fn_802CAFC0(world->collision, collisionData, collisionSize);

            int used = lbl_805A0EB8->reserved + lbl_805A0EB8->used;
            unsigned int available = lbl_805A0EB8->capacity <= used
                ? 0 : lbl_805A0EB8->capacity - used;

            if ((unsigned int)(local0.size << 10) > available) {
                lbl_805A0EB8->failed = 1;
                fn_802EFFAC(world, bodies[0]->owner);
            } else {
                RECORD(0x82)
                char* extra = world->extra;
                if (extra != 0) {
                    extra += 8;
                }
                int size0 = local0.size;
                void* data0 = local0.data;
                fn_802CAEE8(world->collision, data0, size0, extra);
                fn_802EFFAC(world, bodies[0]->owner);
            }
        }

        RECORD(0x8b)


    }
}
