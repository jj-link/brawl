#pragma force_active on
#define V(n) virtual void f##n();
#define T10(a) V(a##0) V(a##1) V(a##2) V(a##3) V(a##4) V(a##5) V(a##6) V(a##7) V(a##8) V(a##9)
#define T100(a) T10(a##0) T10(a##1) T10(a##2) T10(a##3) T10(a##4) T10(a##5) T10(a##6) T10(a##7) T10(a##8) T10(a##9)

struct Cls164 { T10(1) T10(2) T10(3) T10(4) T10(5) T10(6) T10(7) T10(8) V(0) V(1) V(2) V(3) V(4) V(5) V(6) virtual void f164(int); };
struct Cls28 { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) virtual void* g(int); };
struct Cls14 { V(0) V(1) V(2) virtual void g(float*); };
struct Cls20 { V(0) V(1) V(2) V(3) V(4) V(5) virtual void g(int, bool); };
struct Cls1c { V(0) V(1) V(2) V(3) V(4) virtual void g(int, unsigned); };
struct Pad8 { char pad[8]; };
struct Cls1c8 : Pad8 { T100(0) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111) virtual void g(int); };
struct Pad3C { char pad[0x3C]; };
struct Sit : Pad3C { T10(0) T10(1) T10(2) T10(3) V(40) V(41) V(42) virtual void* g(); };
struct Q { char pad[0x10]; Cls1c8* a; Cls20* b; char pad2[0x3C]; Cls164* c; char pad3[0xC]; Cls1c* d; };
struct P { char pad[8]; Sit* h; char pad2[0xCC]; Q* q; };
struct R { char pad[0xC]; Cls14* a; char pad2[0x44]; Cls28* b; };
struct Obj { char pad[0x60]; P* p; char pad2[0x150]; R* r; };

extern "C" {
void* getInstance__9itManagerFv();
void* getItemFromInstanceId__9itManagerFi(void*, int);
float getParamFloat__8BaseItemFUl(void*, unsigned long);
int getSituationKind__23soExternalValueAccesserFP11StageObject(void*);
extern float lbl_41_rodata_10BC;

int fn_41_50B2C(Obj* o, int id) {
    o->p->q->c->f164(1);
    o->r->b->g(4);
    void* it = getItemFromInstanceId__9itManagerFi(getInstance__9itManagerFv(), id);
    float v[3];
    v[0] = getParamFloat__8BaseItemFUl(it, 3);
    v[1] = getParamFloat__8BaseItemFUl(it, 4);
    v[2] = lbl_41_rodata_10BC;
    o->r->a->g(v);
    o->p->h->g();
    if (getSituationKind__23soExternalValueAccesserFP11StageObject(it) == 0) {
        o->p->q->a->g(0);
        o->p->q->b->g(0, false);
        o->p->q->d->g(0x17, 0x10000006);
    } else {
        o->p->q->d->g(0x16, 0x10000006);
    }
    return 1;
}
}
