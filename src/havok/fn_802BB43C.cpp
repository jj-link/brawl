#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
#pragma fp_contract on
extern "C" int __cntlzw(unsigned int);
extern "C" char lbl_8040FF00[];
extern float lbl_805A3F90;

struct TimerEntry { const char* name; u32 time; u32 pad; };
struct Timer {
    u32 a;
    TimerEntry* cursor;
    u32 b;
    TimerEntry* end;
    u32 c[2];
};
extern "C" Timer lbl_80532448;

#define REC(offset)                                                         \
    {                                                                       \
        Timer* timer = &lbl_80532448;                                        \
        s8 c = (s8)(((u32)timer->end <<                                         \
             __cntlzw((u32)timer->end ^ (u32)timer->cursor)) >> 31);          \
        if (((u32)(-c | c) >> 31) != 0) {                                    \
            TimerEntry* entry = timer->cursor;                               \
            entry->name = lbl_8040FF00 + (offset);                           \
            register u32 t;                                                  \
            asm { mftb t }                                                   \
            entry->time = t;                                                 \
            timer->cursor = entry + 1;                                       \
        }                                                                    \
    }

extern "C" char lbl_804877E8[];
struct Vtable_Class_802BB34C {
    void* vtable;
    Vtable_Class_802BB34C() {}
};
class Class_802BB34C : public Vtable_Class_802BB34C {
public:
    Class_802BB34C(int, int, float, float, float, float, float, float, float, float);
    Class_802BB34C(float);
    ~Class_802BB34C() {}
    u16 type;
    u16 pad6;
    u32 unk8;
    float radius;
};
class Agent {
public:
    virtual ~Agent();
    virtual void fn_802D639C();
    virtual void fn_802D5E1C();
    virtual void fn_802D5F28();
    virtual void fn_802D0890();
    virtual void fn_802D6004(void*, int, int, int);
};

extern "C" void __ct__14Class_802BB34CFiiffffffff(void*, float);
inline Class_802BB34C::Class_802BB34C(float r) { __ct__14Class_802BB34CFiiffffffff(this, r); }

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    Vec4& self() { return *this; }
    Vec4& operator=(const Vec4& v) {
        x=v.x; y=v.y; z=v.z; w=v.w;
        self(); self(); self(); self();
        return *this;
    }
    void assign(const Vec4& v) { x=v.x; y=v.y; z=v.z; w=v.w; }
    void setRotatedDir(const struct Matrix& m, const Vec4& v);
    void setAdd4(const Vec4& p, const Vec4& q) {
        x=p.x+q.x; y=p.y+q.y; z=p.z+q.z; w=p.w+q.w;
    }
};
struct Matrix {
    Vec4 a, b, c, d;
    Vec4 e0, e1, e2, e3, e4, e5;
    float r0, r1, r2, r3, r4;
    u16 f, g;
    void set(Vec4 dd, Vec4 cc, Vec4 bb, Vec4 aa) {
        a=aa; b=bb; c=cc; d=dd;
    }
    Matrix* copy(const Matrix& v) {
        set(v.d, v.c, v.b, v.a);
        e0=v.e0;
        e1.assign(v.e1);
        e2.assign(v.e2);
        e3.assign(v.e3);
        e4.assign(v.e4);
        e5.assign(v.e5);
        r0=v.r0; r1=v.r1; r2=v.r2; r3=v.r3; r4=v.r4;
        f=v.f; g=v.g;
        return this;
    }
};
inline void Vec4::setRotatedDir(const Matrix& m, const Vec4& b) {
    const float b2 = b.z;
    const float b1 = b.y;
    const float b0 = b.x;
    x = b0 * m.a.x + b1 * m.b.x + b2 * m.c.x;
    y = b0 * m.a.y + b1 * m.b.y + b2 * m.c.y;
    z = b0 * m.a.z + b1 * m.b.z + b2 * m.c.z;
}
struct Data { char pad[0x10]; Vec4 v[1]; };
struct Src { Data* data; u32 pad; Matrix* mat; };
struct Entry { int index; Agent* obj; };
struct Mgr { char pad[0xC]; Entry* entries; int count; };
struct Args { Class_802BB34C* local; int index; Matrix* mat; Src* src; };

extern "C" void fn_802BB43C(Mgr* mgr, Src* src, int a, int b, int c) {
    REC(0)

    Matrix* source = src->mat;
    Data* vertices = src->data;
    __attribute__((aligned(16))) unsigned char storage[sizeof(Matrix)];
    Matrix& matrix = *(Matrix*)storage;
    Matrix* transform = matrix.copy(*source);

    Class_802BB34C local0(lbl_805A3F90);

    float zero = lbl_805A3F90;
    Args args;
    args.src = src;
    args.mat = transform;
    Entry* e = mgr->entries;
    Vec4* base = (Vec4*)((char*)vertices + 0x10);

    for (int i = mgr->count - 1; i >= 0; --i) {
        Matrix* original = src->mat;
        Vec4* v = base + e->index;
        Vec4 temp;
        temp.setRotatedDir(matrix, *v);
        temp.w = zero;
        matrix.d.setAdd4(original->d, temp);
        matrix.e0.setAdd4(original->e0, temp);
        matrix.e1.setAdd4(original->e1, temp);
        local0.radius = v->w;
        args.local = &local0;
        args.index = i;
        e->obj->fn_802D6004(&args, a, b, c);
        ++e;
    }

    REC(0xe)
}