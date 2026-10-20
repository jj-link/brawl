#pragma force_active on
typedef unsigned char u8;

#define V(n) virtual void v##n(float) = 0;
#define V10(b) V(b##0) V(b##1) V(b##2) V(b##3) V(b##4) V(b##5) V(b##6) V(b##7) V(b##8) V(b##9)

struct Base {
    u8 pad[0x3c];
};

struct GimmickVT : Base {
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9) V10(10) V10(11)
};

extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

extern "C" void fn_67_B594(void* self, float deltaFrame) {
    GimmickVT* g = (GimmickVT*)self;
    update__9grGimmickFf(self, deltaFrame);
    if (*((u8*)self + 0xc8)) {
        g->v112(deltaFrame);
        g->v114(deltaFrame);
    }
}
