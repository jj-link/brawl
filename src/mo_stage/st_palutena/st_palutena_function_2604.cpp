#pragma force_active on
typedef unsigned char u8;

#define V(n) virtual void v##n(float);
#define V10(b) V(b##0) V(b##1) V(b##2) V(b##3) V(b##4) V(b##5) V(b##6) V(b##7) V(b##8) V(b##9)

struct Base {
    u8 pad[0x3c];
};

struct Gimmick : Base {
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9) V10(10) V10(11)
    u8 pad40[0x88];
    u8 unkC8;
};

extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

extern "C" void fn_67_2604(void* self, float deltaFrame) {
    Gimmick* g = (Gimmick*)self;
    update__9grGimmickFf(self, deltaFrame);
    if (g->unkC8) {
        g->v112(deltaFrame);
        g->v113(deltaFrame);
        g->v114(deltaFrame);
        g->v115(deltaFrame);
        g->v116(deltaFrame);
    }
}
