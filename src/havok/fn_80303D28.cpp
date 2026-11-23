#pragma force_active on
#pragma fp_contract on
typedef struct Vec4 { float v[4]; } Vec4 __attribute__((aligned(16)));
extern float lbl_805A45C4;
extern float lbl_805A45CC;
struct Key { unsigned char a, b; unsigned short c; };
extern "C" void fn_80303018(void*, void*, Key*, float);
extern "C" void fn_80303D28(void* a, void* b, int x, int y, int i, int j, const Vec4* v, const Vec4* w, float f) {
    Key k;
    Vec4 q, p;
    k.c = 0;
    float* pv = &p.v[x];
    p.v[0] = v->v[0]; p.v[1] = v->v[1]; p.v[2] = v->v[2]; p.v[3] = v->v[3];
    q.v[0] = w->v[0]; q.v[1] = w->v[1]; q.v[2] = w->v[2]; q.v[3] = w->v[3];
    *pv = lbl_805A45CC;
    q.v[y] = lbl_805A45CC;
    int s = ((p.v[0] < lbl_805A45C4) << 3) | ((p.v[1] < lbl_805A45C4) << 2) | ((p.v[2] < lbl_805A45C4) << 1) | (p.v[3] < lbl_805A45C4);
    int t = ((q.v[0] < lbl_805A45C4) << 3) | ((q.v[1] < lbl_805A45C4) << 2) | ((q.v[2] < lbl_805A45C4) << 1) | (q.v[3] < lbl_805A45C4);
    k.a = x | 0x10 | ((s << 4) & 0xe0);
    k.b = y + (((t & 0xe) ^ 0xe) << 4);
    fn_80303018(a,b,&k,f);
    int n;
    if (i == 0) { n = 3; } else if (i == 1) { n = 2; } else { n = 1; }
    int mask = 1 << (n + 4);
    if (j == 0) { n = 3; } else if (j == 1) { n = 2; } else { n = 1; }
    int mask2 = 1 << (n + 4);
    k.a ^= mask;
    fn_80303018(a,b,&k,f);
    k.b ^= mask2;
    fn_80303018(a,b,&k,f);
    k.a ^= mask;
    fn_80303018(a,b,&k,f);
}
