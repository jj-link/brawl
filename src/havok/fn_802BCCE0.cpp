#include <types.h>

#pragma force_active on

extern "C" int __cntlzw(unsigned int);
extern "C" int fn_802D5E1C(void*);
extern "C" void __ct__14Class_802BB34CFiiffffffff(void*, float);

struct TimerEntry {
    const char* name;
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
extern char lbl_8040FF00[];
extern const float lbl_805A3F90;

#define RECORD(offset)                                                     \
    {                                                                      \
        Timer* timer = &lbl_80532448;                                       \
        signed char c = (signed char)(                                     \
            ((unsigned int)timer->end <<                                   \
             __cntlzw((unsigned int)timer->end ^                            \
                      (unsigned int)timer->current)) >> 31);                 \
        if (((unsigned int)(-c | c) >> 31) != 0) {                          \
            TimerEntry* entry = timer->current;                            \
            entry->name = lbl_8040FF00 + (offset);                          \
            register u32 t;                                                \
            asm { mftb t }                                                 \
            entry->time = t;                                               \
            timer->current = entry + 1;                                    \
        }                                                                  \
    }

extern "C" char lbl_804877E8[];

struct Vtable_Class_802BB34C {
    void* vtable;

    Vtable_Class_802BB34C() : vtable(lbl_804877E8) {}
    Vtable_Class_802BB34C(int) {}
};

class Class_802BB34C : public Vtable_Class_802BB34C {
public:
    Class_802BB34C(int, int, float, float, float, float,
                  float, float, float, float);

    Class_802BB34C(float f) : Vtable_Class_802BB34C(0) {
        __ct__14Class_802BB34CFiiffffffff(this, f);
    }

    ~Class_802BB34C() {}

    u16 field4;
    u16 field6;
    u32 field8;
    float radius;
};

namespace VirtualShape {
class Class_802BB34C {
public:
    virtual ~Class_802BB34C();
    virtual void fn_802D639C();
    virtual int fn_802D5E1C();
};
}

struct Transform;

struct Vector4 {
    float x, y, z, w;

    Vector4() {}

    Vector4(const Vector4& other)
        : x(other.x), y(other.y), z(other.z), w(other.w) {}

    Vector4& self() { return *this; }

    Vector4& operator=(const Vector4& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
        self();
        self();
        self();
        self();
        return *this;
    }

    inline void setRotatedDir(const Transform& r, const Vector4& b);

    void setAdd4(const Vector4& p, const Vector4& q) {
        x = p.x + q.x;
        y = p.y + q.y;
        z = p.z + q.z;
        w = p.w + q.w;
    }
};

struct Transform {
    Vector4 column0;
    Vector4 column1;
    Vector4 column2;
    Vector4 column3;
    float f40, f44, f48, f4c;
    float f50, f54, f58, f5c;
    float f60, f64, f68, f6c;
    float f70, f74, f78, f7c;
    float f80, f84, f88, f8c;
    float f90, f94, f98, f9c;
    float fa0, fa4, fa8, fac;
    float fb0;
    u16 fieldB4;
    u16 fieldB6;

    void copyColumns(Vector4 d, Vector4 c, Vector4 b, Vector4 a) {
        column0 = a;
        column1 = b;
        column2 = c;
        column3 = d;
    }

    Transform() {}

    void set(const Transform& t) {
        copyColumns(t.column3, t.column2, t.column1, t.column0);
        f40 = t.f40;
        f44 = t.f44;
        f48 = t.f48;
        f4c = t.f4c;
        f50 = t.f50;
        f54 = t.f54;
        f58 = t.f58;
        f5c = t.f5c;
        f60 = t.f60;
        f64 = t.f64;
        f68 = t.f68;
        f6c = t.f6c;
        f70 = t.f70;
        f74 = t.f74;
        f78 = t.f78;
        f7c = t.f7c;
        f80 = t.f80;
        f84 = t.f84;
        f88 = t.f88;
        f8c = t.f8c;
        f90 = t.f90;
        f94 = t.f94;
        f98 = t.f98;
        f9c = t.f9c;
        fa0 = t.fa0;
        fa4 = t.fa4;
        fa8 = t.fa8;
        fac = t.fac;
        fb0 = t.fb0;
        fieldB4 = t.fieldB4;
        fieldB6 = t.fieldB6;
    }
};

#pragma fp_contract on
inline void Vector4::setRotatedDir(const Transform& r, const Vector4& b) {
    float bz = b.z;
    float by = b.y;
    float bx = b.x;
    x = bx * r.column0.x + by * r.column1.x + bz * r.column2.x;
    y = bx * r.column0.y + by * r.column1.y + bz * r.column2.y;
    z = bx * r.column0.z + by * r.column1.z + bz * r.column2.z;
    w = lbl_805A3F90;
}

struct SphereCollection {
    char padding[0xc];
    int count;
    Vector4 spheres[1];
};

struct Body {
    SphereCollection* shape;
    void* key;
    Transform* transform;
};

struct OtherBody {
    VirtualShape::Class_802BB34C* shape;
};

struct Result {
    char padding[4];
    signed char stop;
};

struct LocalBody {
    Class_802BB34C* shape;
    int key;
    Transform* transform;
    Body* parent;
};

typedef void (*DispatchFunction)(LocalBody*, OtherBody*, void*, Result*);

struct DispatcherRef {
    char* dispatcher;
};

extern "C" void fn_802BCCE0(
    Body* self,
    OtherBody* other,
    DispatcherRef* dispatcherRef,
    Result* result
) {
    RECORD(0)

    SphereCollection* collection = self->shape;
    __attribute__((aligned(16))) Transform transform;
    Transform* transformPtr = &transform;
    transform.set(*self->transform);
    Class_802BB34C local0(lbl_805A3F90);

    LocalBody body;
    body.parent = self;
    VirtualShape::Class_802BB34C* otherShape = other->shape;
    body.transform = transformPtr;

    int shapeType = otherShape->fn_802D5E1C();
    Vector4* spheres = collection->spheres;

    for (int i = 0; i < collection->count; ++i) {
        Vector4 delta;
        delta.setRotatedDir(transform, spheres[i]);

        transform.column3.setAdd4(self->transform->column3, delta);

        local0.radius = spheres[i].w;
        body.shape = &local0;
        body.key = i;

        int localType = fn_802D5E1C(&local0);
        char* dispatcher = dispatcherRef->dispatcher;
        unsigned char index =
            ((unsigned char*)((u32)dispatcher + (localType << 5)))[shapeType + 0x190];
        DispatchFunction function =
            *(DispatchFunction*)(dispatcher + 0x994 + index * 0x14);
        function(&body, other, dispatcherRef, result);

        signed char stop = result->stop;
        if (((unsigned int)(-stop | stop) >> 31) != 0)
            break;
    }

    RECORD(0x0e)
}
