#pragma force_active on
extern "C" void fn_801B8458(void*, int);
extern const float lbl_805A3440;

struct Ent {
    char pad[0x54];
    float a;
    float b;
    int c;
    int d;
};

static inline float calc(char* self, int off) {
    Ent* p = (Ent*)(self + off);
    if (p->d >= p->c) {
        return p->b;
    }
    return p->a + ((float)p->d * (p->b - p->a)) / (float)p->c;
}

extern "C" void fn_801B8390(char* self, int idx, int n) {
    if (n == 0) {
        fn_801B8458(self, idx);
        return;
    }
    int off = idx * 16;
    float v = calc(self, off);
    Ent* q = (Ent*)((int)self + off);
    q->a = v;
    q->b = lbl_805A3440;
    q->c = (n + 2) / 3;
    q->d = 0;
}
