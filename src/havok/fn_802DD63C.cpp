#pragma force_active on
#pragma use_lmw_stmw on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct Node { u16 a, b, type, count, flags; };
struct Sub { char pad[0x58]; void* p; };
struct Info { char pad[0x9c]; int flag; };
struct Stats { char pad[8]; int f8, fc, f10, f14; Info* info; };
struct Counts { char pad[0x14]; u16 a, b, c; };
struct Owner { char pad[8]; Stats* stats; char pad2[8]; Sub* x; Sub* y; char pad3[0xc]; Counts* counts; };
struct Obj { char pad[0xc]; u8* indices; int count; int cap; char pad2[0x10]; Owner* owner; Node* node; };
struct Array { u8* data; int size; int capacity; };

extern const f32 lbl_805A42B8;
extern "C" void* fn_802DA2C8(void*);
extern "C" void fn_802EA884(void*);
extern "C" void fn_802F58CC(void*, void*, void*, int);
extern "C" void fn_8027CE3C(void*, int);

static inline u16 impl(Obj* obj, s32* out1, void** out2) {
    Node* n6 = obj->node;
    u16 t29 = n6->type;
    n6->flags |= 4;
    Node* old = obj->node;
    s32 t = old->type;
    Node* nn = (Node*)fn_802DA2C8(old);
    obj->node = nn;
    u32 base = ((u32)nn + 0x37) & ~15u;
    s32 first = base + ((s32)t << 5);
    u8* entry = (u8*)(base + (nn->count << 5) + t * 0x14);
    *(f32*)entry = lbl_805A42B8;
    *(f32*)(entry + 4) = lbl_805A42B8;
    entry[0xf] = 1;
    if ((s32)t > 0 && !(entry[-5] & 2)) {
        entry[0xf] |= 2;
    }
    *out1 = first;
    *out2 = entry;

    s32 v29, v30, v31;
    v31 = 0;
    v30 = 0;
    s32 v25 = ((s32)t29 + 1) * 0x30 + 0x80;
    v29 = 0;
    if ((s32)t29 == 1) {
        v30 = 4;
        v31 = 0x20;
        v29 = 1;
    }
    if (obj->owner->stats->info->flag) {
        fn_802EA884(obj->owner->x->p);
        fn_802EA884(obj->owner->y->p);
    }
    Owner* ow = obj->owner;
    Stats* st = ow->stats;
    if (st->f8 > v25) v25 = st->f8;
    st->f8 = v25;
    s32 tmp = v31 + 0x30;
    if (v25 > tmp) tmp = v25;
    st->f8 = tmp;
    st->fc = st->fc + v31 + 0x30;
    st->f10 = st->f10 + v30 + 4;
    st->f14 = st->f14 + v29 + 1;
    Counts* c = ow->counts;
    if (c) {
        s32 cc = c->c + v29 + 1;
        s32 cb = v30 + c->b;
        s32 ca = v31 + c->a;
        c->c = cc;
        ca += 0x30;
        cb += 4;
        c->a = ca;
        c->b = cb;
    }
    Node* cur = obj->node;
    if (old != cur) fn_802F58CC(obj->owner, old, cur, cur->b);

    s32 i;
    for (i = obj->count - 1; i >= 0; i--) {
        if (obj->indices[i] == 0xff) {
            obj->indices[i] = (u8)t;
            goto done;
        }
    }
    {
        u8 val = (u8)t;
        if (((Array*)&obj->indices)->size == (s32)(obj->cap & 0x3FFFFFFF)) {
            fn_8027CE3C(&obj->indices, 1);
        }
        obj->indices[obj->count++] = val;
        i = obj->count - 1;
    }
done:
    return (u16)i;
}
extern "C" u16 fn_802DD63C(Obj* obj, s32* out1, void** out2) { return impl(obj, out1, out2); }
