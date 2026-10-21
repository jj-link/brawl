#pragma force_active on
typedef unsigned char u8;

struct Vec3f {
    float x, y, z;
};

struct grHit {
    Vec3f a, b;
    char pad18[12];
    float r;
    char pad28[20];
    int flag;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

class grMadein {
public:
    void setHitPoint(float, Vec3f*, Vec3f*, bool, int);

    char pad0[0x70];
    int heap;
    char pad74[0xEC];
    grHit* hit;
    char pad164[8];
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 flag5 : 1;
    u8 rest : 5;
};

void grMadein::setHitPoint(float r, Vec3f* a, Vec3f* b, bool flag, int v) {
    if (!hit)
        hit = (grHit*)__nw__FUlQ25Heaps8HeapType(0x40, heap);

    flag7 = flag;
    flag5 = 1;
    hit->r = r;
    hit->a = *a;
    hit->b = *b;
    hit->flag = v;
}
