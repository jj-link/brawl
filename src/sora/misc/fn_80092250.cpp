#pragma force_active on
extern "C" {
void fn_800937B8(void*, int);
void fn_8009BD44(void*, void*, void*);
void fn_801EC158(void*);
void fn_801EC868(void*, void*, float, float, float);
}

struct V3 {
    float x, y, z;
};

struct Pair {
    V3 b, a;
};

struct Blk {
    unsigned int w[12];
};

extern "C" void fn_80092250(char* self) {
    Blk blk;
    float f98[12];
    float f68[12];
    float f38[12];
    Pair v;
    unsigned int* q;
    unsigned int* q2;
    int cnt;

    q = *(unsigned int**)(*(char**)self);
    blk = *(Blk*)(q + 0x37);
    fn_8009BD44(&blk, f98, f68);

    cnt = *(int*)(self + 4);
    q2 = ((unsigned int**)(*(char**)self))[cnt - 1];
    v.a.x = f98[3];
    v.a.y = f98[7];
    v.a.z = f98[11];

    blk = *(Blk*)(q2 + 0x37);
    fn_8009BD44(&blk, f98, f68);

    v.b.x = f98[3];
    v.b.y = f98[7];
    v.b.z = f98[11];

    Pair p = v;
    fn_801EC158(f38);
    fn_801EC868(f38, self + 0x68, p.a.x, p.a.y, p.a.z);
    fn_801EC868(f38, self + 0x98, p.b.x, p.b.y, p.b.z);
    fn_800937B8(self, 1);
}
