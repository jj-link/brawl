#pragma force_active on
extern "C" {
extern char lbl_123_data_2238[8];
extern char lbl_123_data_1AF4[8];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getPos__23soExternalValueAccesserFP11StageObject(void*, void*);
float getLr__23soExternalValueAccesserFP11StageObject(void*);
int getSituationKind__23soExternalValueAccesserFP11StageObject(void*);
}
#define P1(n, S) virtual void* p##n##a S; virtual void* p##n##b S; virtual void* p##n##c S; virtual void* p##n##d S; virtual void* p##n##e S; virtual void* p##n##f S; virtual void* p##n##g S; virtual void* p##n##h S; virtual void* p##n##i S; virtual void* p##n##j S;
#define ALL(S) P1(0,S) P1(1,S) P1(2,S) P1(3,S) P1(4,S) P1(5,S) P1(6,S) P1(7,S) P1(8,S) P1(9,S) P1(10,S) P1(11,S)
struct Vec3x { float x, y, z; };
struct W0 { ALL(()) };
struct W1 { ALL((int)) };
struct W2 { ALL((int, int)) };
struct G { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void change(int, bool); };
struct B8 { int a, b; };
struct Y1 : B8 { ALL((int)) };
struct Y2 : B8 { ALL((int, int)) };
struct B3c { char pad[0x3c]; };
struct T : B3c { ALL(()) };
struct M { virtual void a0(); virtual void a1(); virtual void a2(); 
  virtual void setPos(Vec3x*); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void setLr(float); };

extern "C" void fn_123_10630(void* unused, char* self) {
    M* c;
    void* obj;
    Vec3x pos;
    W1* a = *(W1**)(*(char**)(self + 0xd8) + 0x84);
    obj = __dynamic_cast(a->p2e(1), 0, lbl_123_data_2238, lbl_123_data_1AF4, 1);
    W1* b = *(W1**)(*(char**)(self + 0xd8) + 0x54);
    b->p8h(1);
    c = *(M**)(*(char**)(self + 0xd8) + 0xc);
    getPos__23soExternalValueAccesserFP11StageObject(&pos, obj);
    c->setPos(&pos);
    c = *(M**)(*(char**)(self + 0xd8) + 0xc);
    c->setLr(getLr__23soExternalValueAccesserFP11StageObject(obj));
    W0* e = *(W0**)(*(char**)(self + 0xd8) + 0xc);
    e->p1j();
    T* t = *(T**)(self + 8);
    t->p4d();
    if (getSituationKind__23soExternalValueAccesserFP11StageObject(obj) == 0 &&
        (unsigned)(*(Y1**)(*(char**)(self + 0xd8) + 0x10))->p11c(0) == 1) {
        (*(G**)(*(char**)(self + 0xd8) + 0x14))->change(0, 0);
    } else {
        (*(G**)(*(char**)(self + 0xd8) + 0x14))->change(2, 0);
        (*(Y2**)(*(char**)(self + 0xd8) + 0x10))->p1j(5, 0);
    }
    (*(W2**)(*(char**)(self + 0xd8) + 0x84))->p1g(1, 0);
}
