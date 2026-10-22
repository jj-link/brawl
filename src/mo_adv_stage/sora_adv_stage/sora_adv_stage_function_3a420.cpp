#pragma force_active on
#define V4(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3();
#define V16(a) V4(a##0) V4(a##1) V4(a##2) V4(a##3)
struct Mng;
struct Sub { int x; };
struct G { char p[0x1BC]; };
struct B {
    char pad0[0x3C];
    V16(a) V16(b) V16(c) V16(d) V16(e) V16(f)
    V4(g)
    virtual void last();
    char pad1[0xBC - 0x40];
    char* data;
    char pad2[0x1A8 - 0xC0];
};
extern "C" {
extern Mng* g_stTriggerMng;
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(Mng*, int, void*);
void fn_40_2E564(Sub&, Sub*, void*, void*, int, int);
void fn_40_3A21C(G*);
void fn_40_3A698(G*);
void fn_40_3AA10(G*);
}
struct W : B, Sub {
    char pad3[0x1BC - 0x1AC];
    char* copied;
};
#define T(off, n) { void* t = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 0, self->copied + off); \
    fn_40_2E564(*self, self, t, self->copied + off, 1, n); }
extern "C" void fn_40_3A420(W* self) {
    fn_40_3A21C((G*)self);
    self->copied = self->data;
    fn_40_3AA10((G*)self);
    fn_40_3A698((G*)self);
    T(0x94, 0)
    T(0x98, 1)
    T(0x9c, 2)
    T(0x90, 3)
    self->last();
}
