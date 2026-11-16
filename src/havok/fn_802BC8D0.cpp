#include <types.h>

#pragma force_active on
#pragma use_lmw_stmw on
#pragma fp_contract on

extern "C" int __cntlzw(unsigned int);
extern "C" char lbl_8040FF00[];
extern float lbl_805A3F90;

struct TimerEntry {
    const char* name;
    unsigned int time;
    unsigned int pad;
};

struct Timer {
    unsigned int a;
    TimerEntry* cursor;
    unsigned int b;
    TimerEntry* end;
    unsigned int c[2];
};

extern Timer lbl_80532448;

#define REC(offset)                                                         \
    {                                                                       \
        Timer* timer = &lbl_80532448;                                        \
        signed char c = (signed char)(                                       \
            ((unsigned int)timer->end <<                                     \
             __cntlzw((unsigned int)timer->end ^                              \
                      (unsigned int)timer->cursor)) >> 31);                  \
        if (((unsigned int)(-c | c) >> 31) != 0) {                            \
            TimerEntry* entry = timer->cursor;                               \
            entry->name = lbl_8040FF00 + (offset);                            \
            register u32 t;                                                  \
            asm { mftb t }                                                  \
            entry->time = t;                                                \
            timer->cursor = entry + 1;                                      \
        }                                                                   \
    }

extern "C" void __ct__14Class_802BB34CFiiffffffff(void*, float);

class Class_802BB34C {
public:
    Class_802BB34C(float r) { __ct__14Class_802BB34CFiiffffffff(this, r); }
    ~Class_802BB34C() {}

    void* vtable;
    unsigned int unk4;
    unsigned int unk8;
    float radius;
};

class Agent {
public:
    virtual ~Agent();
    virtual void fn_802D639C();
    virtual void fn_802D5E1C(void*, void*, void*, void*);
};

struct Vec4 {
    float x, y, z, w;

    Vec4() {}

    Vec4(const Vec4& v)
        : x(v.x), y(v.y), z(v.z), w(v.w) {}

    Vec4& self() { return *this; }

    Vec4& operator=(const Vec4& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        self();
        self();
        self();
        self();
        return *this;
    }

    void assign(const Vec4& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    inline void setRotatedDir(const struct Matrix& m, const Vec4& b);

    void setAdd4(const Vec4& p, const Vec4& q) {
        x = p.x + q.x;
        y = p.y + q.y;
        z = p.z + q.z;
        w = p.w + q.w;
    }
};

struct Matrix {
    Vec4 a, b, c, d;
    Vec4 e0, e1, e2, e3, e4, e5;
    float r0, r1, r2, r3, r4;
    unsigned short f, g;

    void set(Vec4 dd, Vec4 cc, Vec4 bb, Vec4 aa) {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
    }

    Matrix* copy(const Matrix& v) {
        set(v.d, v.c, v.b, v.a);
        e0 = v.e0;
        e1.assign(v.e1);
        e2.assign(v.e2);
        e3.assign(v.e3);
        e4.assign(v.e4);
        e5.assign(v.e5);
        r0 = v.r0;
        r1 = v.r1;
        r2 = v.r2;
        r3 = v.r3;
        r4 = v.r4;
        f = v.f;
        g = v.g;
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

struct Entry {
    int index;
    Agent* agent;
};

struct Vertices {
    char pad[16];
    Vec4 data[1];
};

struct Collection {
    Vertices* verts;
    int unk4;
    Matrix* matrix;
    Collection* parent;
};

struct Group {
    char pad[12];
    Entry* entries;
    int count;
};

struct Flags {
    char pad[4];
    signed char flag;
};

struct Body {
    Class_802BB34C* local;
    int index;
    Matrix* matrix;
    Collection* parent;
};

extern "C" void fn_802BC8D0(
    Group* group, Collection* col, void* a2, void* a3, Flags* flags)
{
    REC(0)

    Matrix* source = col->matrix;
    Vertices* vertices = col->verts;
    __attribute__((aligned(16))) unsigned char storage[sizeof(Matrix)];
    Matrix& matrix = *(Matrix*)storage;
    Matrix* transform = matrix.copy(*source);

    Class_802BB34C local(lbl_805A3F90);

    Body body;
    body.parent = col;
    body.matrix = transform;

    Vec4* verts = vertices->data;
    float zero = lbl_805A3F90;
    Entry* entry = group->entries;

    for (int index = group->count - 1; index >= 0; --index) {
        const Vec4& vertex = verts[entry->index];
        Vec4 temp;
        temp.setRotatedDir(matrix, vertex);
        temp.w = zero;
        matrix.d.setAdd4(col->matrix->d, temp);

        local.radius = vertex.w;
        body.local = &local;
        body.index = index;

        entry->agent->fn_802D5E1C(&body, a2, a3, flags);

        signed char f = flags->flag;
        if (((unsigned int)(-f | f) >> 31) != 0)
            break;

        ++entry;
    }

    REC(0xe)
}
