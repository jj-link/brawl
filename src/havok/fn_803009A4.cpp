#pragma force_active on
#pragma fp_contract on

struct Vec { float x, y, z, w; } __attribute__((aligned(16)));
struct Matrix { float m[4][4]; } __attribute__((aligned(16)));
struct State {
    int countA, countB, limitA, limitB;
    char flag; char pad[3]; int changed; char pad1[8];
    Vec a[4], unused[4], b[4], localB[4];
    Vec dir; float pad3[16]; int status;
    State() : flag(0) {}
};
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual void slot11(void*, int, Vec*);
    char pad[8]; float radius;
};
struct Node { Object_vptr_0* shape; void* key; Matrix* transform; };
struct Pair { Node* a; Node* b; char pad[8]; Matrix matrix; };
struct Input { short indices[4]; signed char countA, countB, limitA, limitB; };
extern "C" void fn_803198C8(State*, Object_vptr_0*, Object_vptr_0*, Matrix*, Vec*);
extern "C" void fn_8031AB44(State*, void*);
extern const float lbl_805A45A8;

extern "C" void fn_803009A4(Object_vptr_0* sa, Input* input, Pair* pair) {
    Object_vptr_0* sb;
    Vec* out = (Vec*)pair;
    pair = (Pair*)sa;
    sa = pair->a->shape;
    sb = pair->b->shape;
    State state;
    state.countA = input->countA;
    state.countB = input->countB;
    state.limitA = input->limitA;
    state.limitB = input->limitB;
    state.changed = 0;
    sa->slot11(input->indices, state.countA, state.a);
    sb->slot11(input->indices + state.countA, state.countB, state.localB);
    Vec v;
    fn_803198C8(&state, sa, sb, &pair->matrix, &v);
    if (state.changed) fn_8031AB44(&state, input);
    Matrix* m = pair->a->transform;
    float x = v.x, y = v.y, z = v.z;
    out->x = z * m->m[2][0] + (x * m->m[0][0] + y * m->m[1][0]);
    out->y = z * m->m[2][1] + (x * m->m[0][1] + y * m->m[1][1]);
    out->z = z * m->m[2][2] + (x * m->m[0][2] + y * m->m[1][2]);
    out->w = lbl_805A45A8;
    float ra = sa->radius;
    float rb = sb->radius;
    out->w = (v.w - ra) - rb;
}