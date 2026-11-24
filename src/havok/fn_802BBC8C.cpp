#include <types.h>

#pragma force_active on
#pragma fp_contract on

extern "C" int __cntlzw(unsigned int);

extern "C" char lbl_804877E8[];
struct Vtable_Class_802BB34C {
    void* vtable;
    Vtable_Class_802BB34C() : vtable(lbl_804877E8) {}
    Vtable_Class_802BB34C(int) {}
};
class Class_802BB34C : public Vtable_Class_802BB34C {
public:
    int a, b;
    float radius;
    Class_802BB34C(int, int, float, float, float, float, float, float, float, float);
    Class_802BB34C(float);
    ~Class_802BB34C() {}
};
extern "C" void __ct__14Class_802BB34CFiiffffffff(void*, float);
inline Class_802BB34C::Class_802BB34C(float r) : Vtable_Class_802BB34C(0) {
    __ct__14Class_802BB34CFiiffffffff(this, r);
}
extern "C" int fn_802D5E1C(Class_802BB34C*);

struct TimerEntry { char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_8040FF00[];
extern float lbl_805A3F90;
#define REC(offset) \
    { \
        Timer* timer = &lbl_80532448; \
        signed char c = (signed char)(((unsigned int)timer->end << \
            __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31); \
        if (((unsigned int)(-c | c) >> 31) != 0) { \
            TimerEntry* entry = timer->current; \
            entry->name = lbl_8040FF00 + (offset); \
            register u32 t; \
            asm { mftb t } \
            entry->time = t; \
            timer->current = entry + 1; \
        } \
    }

struct Vec {
    float x, y, z, w;
    Vec() {}
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    Vec& self() { return *this; }
    void setRotatedDir(const struct Transform& m, const Vec& b);
    void setAdd4(const Vec& p, const Vec& q) {
        x = p.x + q.x;
        y = p.y + q.y;
        z = p.z + q.z;
        w = p.w + q.w;
    }
    Vec& operator=(const Vec& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        self(); self(); self(); self();
        return *this;
    }
};
struct Transform {
    Vec x, y, z, t;
    float rest[29];
    unsigned short a, b;
    Transform() {}
    void set(Vec d, Vec c, Vec b, Vec a) { x = a; y = b; z = c; t = d; }
    void copy(const Transform& o) {
        set(o.t, o.z, o.y, o.x);
        copyTail(o);
    }
    void copyTail(const Transform& o) {
        rest[0] = o.rest[0];
        rest[1] = o.rest[1];
        rest[2] = o.rest[2];
        rest[3] = o.rest[3];
        rest[4] = o.rest[4];
        rest[5] = o.rest[5];
        rest[6] = o.rest[6];
        rest[7] = o.rest[7];
        rest[8] = o.rest[8];
        rest[9] = o.rest[9];
        rest[10] = o.rest[10];
        rest[11] = o.rest[11];
        rest[12] = o.rest[12];
        rest[13] = o.rest[13];
        rest[14] = o.rest[14];
        rest[15] = o.rest[15];
        rest[16] = o.rest[16];
        rest[17] = o.rest[17];
        rest[18] = o.rest[18];
        rest[19] = o.rest[19];
        rest[20] = o.rest[20];
        rest[21] = o.rest[21];
        rest[22] = o.rest[22];
        rest[23] = o.rest[23];
        rest[24] = o.rest[24];
        rest[25] = o.rest[25];
        rest[26] = o.rest[26];
        rest[27] = o.rest[27];
        rest[28] = o.rest[28];
        a = o.a;
        b = o.b;
    }
};
inline void Vec::setRotatedDir(const Transform& m, const Vec& b) {
    const float b2 = b.z;
    const float b1 = b.y;
    const float b0 = b.x;
    x = b0 * m.x.x + b1 * m.y.x + b2 * m.z.x;
    y = b0 * m.x.y + b1 * m.y.y + b2 * m.z.y;
    z = b0 * m.x.z + b1 * m.y.z + b2 * m.z.z;
}

struct Data { char pad[12]; int count; Vec spheres[1]; };
struct Self { Data* data; int pad; Transform* transform; };

namespace VirtualShape {
class Class_802BB34C {
public:
    virtual ~Class_802BB34C();
    virtual void fn_802D639C();
    virtual int fn_802D5E1C();
};
}

struct Arg { VirtualShape::Class_802BB34C* object; };
struct Context { char* data; };
struct Callback { Class_802BB34C* shape; int index; Transform* transform; Self* self; };
typedef void (*Function)(Callback*, Arg*, Context*, void*);

extern "C" void fn_802BBC8C(Self* self, Arg* arg, Context* ctx, void* other) {
    Transform* trans;
    REC(0)
    float zero;

    Transform* src = self->transform;
    Data* data = self->data;
    Vec* spheres;
    __attribute__((aligned(16))) Transform transform;
    Vec* p;
    trans = &transform;
    transform.copy(*src);
    Class_802BB34C local0(lbl_805A3F90);
    Callback callback;
    callback.self = self;
    VirtualShape::Class_802BB34C* object = arg->object;
    callback.transform = trans;
    int type = object->fn_802D5E1C();
    zero = lbl_805A3F90;
    spheres = data->spheres;
    for (int i = 0; i < data->count; ++i) {
        p = &spheres[i];
        Vec out;
        out.setRotatedDir(transform, *p);
        out.w = zero;
        transform.t.setAdd4(self->transform->t, out);
        local0.radius = p->w;
        callback.shape = &local0;
        callback.index = i;
        int id = fn_802D5E1C(&local0);
        char* dispatcher = ctx->data;
        unsigned char index = ((unsigned char*)((u32)dispatcher + (id << 5)))[type + 0x190];
        Function func = *(Function*)(dispatcher + 0x998 + index * 20);
        func(&callback, arg, ctx, other);
    }

    REC(14)
}
