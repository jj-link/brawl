#pragma force_active on
struct Entry { const char* name; unsigned int time; int unused; };
struct Monitor { int unused; Entry* current; int unused2; Entry* end; };
struct Arg {
    float m[16];
    void set(float v15, float v14, float v13, float v12, float v11, float v10, float v9, float v8, float v7, float v6, float v5, float v4, float v3, float v2, float v1, float v0) {
        m[0] = v0;
        m[1] = v1;
        m[2] = v2;
        m[3] = v3;
        m[4] = v4;
        m[5] = v5;
        m[6] = v6;
        m[7] = v7;
        m[8] = v8;
        m[9] = v9;
        m[10] = v10;
        m[11] = v11;
        m[12] = v12;
        m[13] = v13;
        m[14] = v14;
        m[15] = v15;
    }
    float s[4];
    float ss;
    void* p0;
    void* p1;
    int zero;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
};
extern "C" {
extern Monitor lbl_80532448;
extern char lbl_804143F8[];
int fn_8031E6FC(Arg*, void*);
void fn_8031F65C(void*, void*, void*, void*, void*, void*);
}
extern "C" int fn_8031EB28(void* a, void* b, float* c, void* d, void* e, void* f, int* g, void* h, float s) {
    Entry* end = lbl_80532448.end;
    signed char test = end > lbl_80532448.current;
    if (((unsigned int)(-test | test) >> 31) != 0) {
        Entry* cur = lbl_80532448.current;
        cur->name = lbl_804143F8;
        register unsigned int t;
        asm { mftb t }
        cur->time = t;
        lbl_80532448.current = cur + 1;
    }
    __declspec(align(16)) Arg arg;
    arg.set(c[15], c[14], c[13], c[12], c[11], c[10], c[9], c[8], c[7], c[6], c[5], c[4], c[3], c[2], c[1], c[0]);
    arg.s[0] = s;
    arg.s[1] = s;
    arg.s[2] = s;
    arg.s[3] = s;
    arg.ss = s * s;
    arg.p0 = a;
    arg.p1 = b;
    arg.p2 = d;
    arg.p3 = e;
    arg.zero = 0;
    arg.p4 = f;
    arg.p5 = g;
    int ret = fn_8031E6FC(&arg, h);
    if (ret == 3) {
        fn_8031F65C(a, b, c, d, e, h);
        *g = 1;
        ret = 1;
    }
    signed char test2 = lbl_80532448.end > lbl_80532448.current;
    if (((unsigned int)(-test2 | test2) >> 31) != 0) {
        Entry* cur = lbl_80532448.current;
        cur->name = lbl_804143F8 + 0xE;
        register unsigned int t;
        asm { mftb t }
        cur->time = t;
        lbl_80532448.current = cur + 1;
    }
    return ret;
}
