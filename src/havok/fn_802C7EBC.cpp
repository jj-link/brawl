#pragma force_active on
#pragma fp_contract on
#include <types.h>

extern "C" int __cntlzw(unsigned int);

struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct M {
    V a, b, c, d;
    M() {}
};

inline void copyMatrix(M* n, const M* mat) {
    V ma, mb, mc, md;
    ma.x = mat->a.x; ma.y = mat->a.y; ma.z = mat->a.z; ma.w = mat->a.w;
    mb.x = mat->b.x; mb.y = mat->b.y; mb.z = mat->b.z; mb.w = mat->b.w;
    mc.x = mat->c.x; mc.y = mat->c.y; mc.z = mat->c.z; mc.w = mat->c.w;
    md.x = mat->d.x; md.y = mat->d.y; md.z = mat->d.z; md.w = mat->d.w;
    n->a.x = ma.x; n->a.y = ma.y; n->a.z = ma.z; n->a.w = ma.w;
    n->b.x = mb.x; n->b.y = mb.y; n->b.z = mb.z; n->b.w = mb.w;
    n->c.x = mc.x; n->c.y = mc.y; n->c.z = mc.z; n->c.w = mc.w;
    n->d.x = md.x; n->d.y = md.y; n->d.z = md.z; n->d.w = md.w;
}

struct Arg4;
struct Arg5;
struct Arg6;
struct Slot;

class Class_80487134 {
public:
    virtual void fn_802C711C();
    virtual void fn_80080A64();
    virtual unsigned short fn_802C7B54(Arg4*, Arg5*, Arg6*, Slot**, int, Slot*);
    virtual void fn_802C7288();
    virtual void fn_802B7A14(unsigned short);
};

struct Node { char pad[0xC]; float f0c; };
struct Arg4 { Node* n; char pad[4]; float* xf; };
struct Part { char pad0[0xC]; float f0c; V v[3]; };
struct Arg5 { Part* part; char pad[4]; M* mtx; };
struct Arg6 { char pad[8]; float f8; };
struct Slot { float p[4]; float q[4]; unsigned short idx; char pad[0xE]; };
struct Tri { char pad[8]; Class_80487134* child; unsigned short handle; };

struct TimerEntry { char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_80487168[];
extern char lbl_8059EFA0[3];
extern float lbl_805A3FE8;

extern "C" int fn_8032561C(float* mtx, float* pts, void* obj, float* out);

#define RECORD(label)                                                          \
    {                                                                          \
        Timer* timer = &lbl_80532448;                                          \
        signed char c = (signed char)(                                         \
            ((u32)timer->end                                                   \
             << __cntlzw((u32)timer->end ^ (u32)timer->current)) >> 31);        \
        if (((u32)(-c | c) >> 31) != 0) {                                      \
            TimerEntry* entry = timer->current;                                \
            entry->name = (char*)(label);                                      \
            register u32 t;                                                    \
            asm { mftb t }                                                     \
            entry->time = t;                                                   \
            timer->current = entry + 1;                                        \
        }                                                                      \
    }

#define RECORD4(label)                                                         \
    {                                                                          \
        TimerEntry* entry;                                                     \
        Timer* timer = &lbl_80532448;                                          \
        signed char c = (signed char)(                                         \
            ((u32)timer->end                                                   \
             << __cntlzw((u32)timer->end ^ (u32)(entry = timer->current))) >> 31); \
        if (((u32)(-c | c) >> 31) != 0) {                                      \
            entry->name = (char*)(label);                                      \
            register u32 t;                                                    \
            asm { mftb t }                                                     \
            entry->time = t;                                                   \
            timer->current = entry + 1;                                        \
        }                                                                      \
    }

extern "C" void fn_802C7EBC(Tri* self, Arg4* a4, Arg5* a5, Arg6* a6, Slot** slots) {
    RECORD(lbl_80487168)
    float* xm;
    Node* node;
    Part* part;
    Slot* s;
    M n;
    V pts[3] __attribute__((aligned(16)));
    float out[8] __attribute__((aligned(16)));
    copyMatrix(&n, a5->mtx);
    part = a5->part;
    const V* input = part->v;
    xm = a4->xf + 12;
    s = *slots;
    node = a4->n;
    for (int i = 0; i < 3; ++i) {
        int j = i * 4;
        float* dst = (float*)pts + j;
        const float* src = (const float*)input + j;
        float z = src[2], y = src[1], x = src[0];
        dst[0] = n.d.x + (x * n.a.x + y * n.b.x + z * n.c.x);
        dst[1] = n.d.y + (x * n.a.y + y * n.b.y + z * n.c.y);
        dst[2] = n.d.z + (x * n.a.z + y * n.b.z + z * n.c.z);
        dst[3] = lbl_805A3FE8;
    }
    int ret = fn_8032561C(xm, (float*)pts, (char*)self + 0x10, out);
    float d = out[4];
    float pr = part->f0c;
    float nr = node->f0c;
    float base = nr + pr;
    float av = a6->f8;
    int code;
    if (d < base + av) {
        float f2 = pr - d;
        s->p[0] = xm[0] + f2 * out[0];
        s->p[1] = xm[1] + f2 * out[1];
        s->p[2] = xm[2] + f2 * out[2];
        s->p[3] = xm[3] + f2 * out[3];
        float dist = out[4] - base;
        s->q[0] = out[0];
        s->q[1] = out[1];
        s->q[2] = out[2];
        s->q[3] = dist;
        code = (ret == 0) ? 1 : 2;
    } else {
        code = 0;
    }
    if (code != 0) {
        if (self->handle == 0xFFFF) {
            self->handle = self->child->fn_802C7B54(a4, a5, a6, slots, 0, s);
        }
        if (self->handle != 0xFFFF) {
            s->idx = self->handle;
            *slots = *slots + 1;
        }
    } else if (self->handle != 0xFFFF) {
        self->child->fn_802B7A14(self->handle);
        self->handle = 0xFFFF;
    }
    RECORD4(lbl_8059EFA0)
}
