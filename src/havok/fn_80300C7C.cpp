#pragma force_active on
#pragma fp_contract on

extern char lbl_804141F0[];
struct Trace { const char* name; char pad[8]; const char* extra; };
struct Params { char pad[12]; float limit; unsigned char flag; char pad2[3]; float a, b; char pad3[8]; float c, d; };
struct Inner { char pad[0x28]; Params* params; };
struct Shape { char pad[0x20]; float value; };
struct State { void* a; void* b; Inner* inner; int other; char pad[0x40]; float value; };
struct Contact { char pad[2]; unsigned char count; };
struct Buffer { char pad[12]; Contact contact; };
struct List { int pad; int* next; };
struct Context { int base; char pad[0x304c]; List* list; };
typedef unsigned char Byte __attribute__((aligned(4)));
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
void fn_80313FB4(State*, Buffer*, void*, Context*, float, float, float);
void fn_803010FC(Local*);
float fn_80301778(Inner*);
void fn_80301100(Contact*, void*, void*, void*, Local*);
void fn_80315A84(Contact*, Local*, int, Context*, int);
void fn_80301780(State*, Contact*, Buffer*, Buffer*, Contact*, void*, Context*);
int fn_80300978(Contact*);
void fn_8030099C(Buffer*, int);
}
#define TRACE(off) { void* t = fn_802AA274(); Byte b = fn_802AA280() >> 24; if (fn_802A0BD8(&b)) { Trace* p = fn_802AA29C(t); p->name = lbl_804141F0 + off; fn_802AA2A4(p); fn_802AA2B0(t, (char*)p + 12); } }
extern "C" void fn_80300C7C(State* s, Contact* out, Buffer* buf, void* v, Context* ctx) {
    void* t = fn_802AA274();
    Byte x = fn_802AA280() >> 24;
    if (fn_802A0BD8(&x)) {
        Trace* p = fn_802AA29C(t);
        p->name = lbl_804141F0;
        fn_802AA2A4(p);
        fn_802AA2B0(t, (char*)p + 12);
    }
    void* t2 = fn_802AA274();
    Byte y = fn_802AA280() >> 24;
    if (fn_802A0BD8(&y)) {
        Trace* p = fn_802AA29C(t2);
        p->name = lbl_804141F0 + 12;
        p->extra = lbl_804141F0 + 21;
        fn_802AA2A4(p);
        fn_802AA2B0(t2, (char*)p + 16);
    }
    Contact* c = &buf->contact;
    float value = s->value;
    Params* p = s->inner->params;
    if (fn_802A0BD8(&p->flag)) {
        float a = fn_803010E4(s->a)->value;
        float delta = fn_802A0C4C(a, fn_803010E4(s->b)->value);
        float base = *fn_800966A4(v, 3);
        float low = fn_802A0C4C(p->a * delta, p->b * delta + base);
        if (!(value >= low)) {
            float high = fn_802A0C4C(p->c * delta, p->d * delta + base);
            TRACE(28)
            fn_80313FB4(s, buf, v, ctx, delta, low, high);
            goto process;
        }
    }
    if (value > p->limit) {
        *fn_800966A4(v, 3) = value;
        if (c->count) {
            TRACE(34)
            Local local;
            fn_803010FC(&local);
            fn_80301778(s->inner);
            fn_80301100(c, v, s->a, s->b, &local);
            fn_80315A84(c, &local, 0, ctx, s->other);
            if (c->count && ctx->list) {
                List* list = ctx->list;
                *list->next++ = ctx->base - c->count * 0x30;
            }
        }
    } else {
    process:
        TRACE(46)
        fn_80301780(s, out, buf, buf, c, v, ctx);
    }
    out->count = c->count;
    TRACE(56)
    TRACE(59)
    fn_8030099C(buf, (fn_80300978(c) + 0x1b) & ~15);
}