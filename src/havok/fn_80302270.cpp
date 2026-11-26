#pragma force_active on
#pragma fp_contract on

#include <../../hk410/include/hkmath/hkMath.h>

extern char lbl_80414230[];
extern float lbl_805A45B0;
extern float lbl_805A45B4;

struct Trace { const char* name; char pad[8]; const char* extra; };
typedef unsigned char Byte __attribute__((aligned(4)));
struct Vec { float v[4]; } __attribute__((aligned(16)));
struct Params { char pad[12]; float limit; unsigned char flag; char pad2[3]; float a, b; char pad3[8]; float c, d; };
struct Inner { char pad[0x28]; Params* params; };
struct Shape { char pad[0x20]; float value; };
struct State { void* a; void* b; Inner* inner; int other; char pad[0x40]; float value; };
struct Contact { char pad[2]; unsigned char count; };
struct Buffer { char pad[12]; Contact contact; };
struct Out { char pad[2]; unsigned char count; char pad2; unsigned int flags; };
struct List { int pad; int* next; };
struct Context { int base; char pad[0x304c]; List* list; };
struct Local { char data[0x120]; } __attribute__((aligned(16)));

extern "C" {
void* fn_802AA274();
unsigned int fn_802AA280();
unsigned int fn_802A0BD8(unsigned char*);
Trace* fn_802AA29C(void*);
void fn_802AA2A4(Trace*);
void fn_802AA2B0(void*, void*);
float fn_802A0C4C(float, float);
Shape* fn_803010E4(void*);
float* fn_800966A4(void*, int);
int fn_802AA2C8(void*);
void* fn_803028EC(int, int);
void fn_803028E8(Vec*);
void* fn_803028FC(void*);
void fn_802DB598(Vec*);
void* fn_802DB624(void*);
void fn_802879F8(Vec*, void*, Vec*);
float fn_80294C58(Vec*, Vec*);
void fn_80294764(Vec*, void*, void*);
void fn_80294C80(Vec*);
void fn_80294740(void*, Vec*);
void fn_803009A4(const State*, Buffer*, Vec*);
void fn_80302904(Contact*, Out*, int);
void fn_80302950(void*, void*, void*, void*);
void fn_80302AA8(Vec*, void*);
void fn_80302B80(void*, void*);
void fn_80302C34(Vec*, Buffer*);
void fn_80313FB4(const State*, Buffer*, void*, Context*, float, float, float);
void fn_803010FC(Local*);
void fn_80301778(Inner*);
void fn_80301100(Contact*, void*, void*, void*, Local*);
void fn_80315A84(Contact*, Local*, int, Context*, int);
void fn_80301780(const State*, Out*, Buffer*, void*, Contact*, void*, Context*);
int fn_80300978(Contact*);
void fn_8030099C(Buffer*, int);
}

#define TRACE(off) { void* t = fn_802AA274(); Byte b = fn_802AA280() >> 24; if (fn_802A0BD8(&b)) { Trace* p = fn_802AA29C(t); p->name = lbl_80414230 + off; fn_802AA2A4(p); fn_802AA2B0(t, (char*)p + 12); } }

extern "C" void fn_80302270(const State* s, Out* out, Buffer* buf, void* v, Context* ctx) {
    float value;
    Vec v90;
    Vec v80;
    Vec v70;
    Vec v60;
    Vec v50;
    void** arr[2];
    unsigned int fa[2];
    unsigned int fb[2];
    int cnt[2];
    int four;
    int zero;
    unsigned int* pa;
    void*** pr;
    unsigned int* pb;
    Contact* c;
    int i;

    TRACE(0)
    {
        void* t2 = fn_802AA274();
        Byte b2 = fn_802AA280() >> 24;
        if (fn_802A0BD8(&b2)) {
            Trace* p = fn_802AA29C(t2);
            p->name = lbl_80414230 + 12;
            p->extra = lbl_80414230 + 21;
            fn_802AA2A4(p);
            fn_802AA2B0(t2, (char*)p + 16);
        }
    }
    arr[0] = (void**)s;
    arr[1] = arr[0] + 1;
    zero = 0;
    value = s->value;
    c = &buf->contact;
    fa[0] = out->flags & 1;
    fa[1] = out->flags & 2;
    fb[0] = out->flags & 4;
    fb[1] = out->flags & 8;
    cnt[0] = zero;
    cnt[1] = zero;
    fn_803028E8(&v80);
    fn_803028E8(&v90);
    fn_802DB598(&v70);
    fn_803009A4(s, buf, &v70);

    float near = lbl_805A45B4;
    float far = lbl_805A45B0;
    pa = fa;
    pr = arr;
    pb = fb;
    i = 0;
    four = 4;
    do {
        if (*pa != 0) {
            int idx = fn_802AA2C8(**pr);
            fn_802DB598(&v60);
            fn_80294764(&v60, fn_803028EC(idx, 1), fn_803028EC(idx, 0));
            fn_80294C80(&v60);
            fn_802879F8(&v60, fn_802DB624(fn_803028FC(**pr)), &v60);
            float dist = hkMath::fabs(fn_80294C58(&v60, &v70));
            if (*pb != 0) {
                if (dist > far) {
                    *pb = zero;
                    int other = s->other;
                    unsigned int f = out->flags;
                    out->flags = f & ~(four << i);
                    fn_80302904(c, out, other);
                }
            } else if (dist < near) {
                *pb = 1;
                int other = s->other;
                unsigned int f = out->flags;
                out->flags = f | (four << i);
                fn_80302904(c, out, other);
            }
        }
        i++;
        pa++;
        pr++;
        pb++;
    } while (i < 2);

    Params* p = s->inner->params;
    if (fn_802A0BD8(&p->flag)) {
        float a = fn_803010E4(s->a)->value;
        float delta = fn_802A0C4C(a, fn_803010E4(s->b)->value);
        float base = *fn_800966A4(v, 3);
        float high;
        float low = fn_802A0C4C(p->a * delta, p->b * delta + base);
        if (!(value >= low)) {
            value = fn_802A0C4C(p->c * delta, p->d * delta + base);
            high = value;
            TRACE(28)
            fn_80313FB4(s, buf, v, ctx, delta, low, high);
            goto process;
        }
    }
    if (value > p->limit) {
        *fn_800966A4(v, 3) = value;
        if (c->count) {
            TRACE(34)
            fn_80302950(arr, fb, &v80, cnt);
            Local local;
            fn_803010FC(&local);
            fn_80301778(s->inner);
            fn_80301100(c, v, s->a, s->b, &local);
            fn_80315A84(c, &local, 0, ctx, s->other);
            if (c->count != 0) {
                List* list = ctx->list;
                if (list != 0) {
                    *list->next++ = ctx->base - c->count * 0x30;
                }
            }
        }
    } else {
    process:
        TRACE(46)
        fn_80302950(arr, fb, &v80, cnt);
        void* src = buf;
        if (fb[0] != 0 || fb[1] != 0) {
            src = &v50;
            fn_80302C34(&v50, buf);
            fn_80302AA8(&v50, fb);
        }
        fn_80301780(s, out, buf, src, c, v, ctx);
        fn_80294740(v, &v70);
    }
    fn_80302B80(arr, cnt);
    out->count = c->count;
    TRACE(56)
    TRACE(59)
    fn_8030099C(buf, (fn_80300978(c) + 0x1b) & ~15);
}
