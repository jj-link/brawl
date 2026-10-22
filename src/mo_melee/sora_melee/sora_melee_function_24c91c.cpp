#pragma force_active on
struct Data { unsigned char a; unsigned char b; };
struct Base { char pad[0x3c]; };
#define V(n) virtual void n();
struct Obj : Base { V(a0)V(a1)V(a2)V(a3)V(a4)V(a5)V(a6)V(a7)V(a8)V(a9)
V(b0)V(b1)V(b2)V(b3)V(b4)V(b5)V(b6)V(b7)V(b8)V(b9)
V(c0)V(c1)V(c2)V(c3)V(c4)V(c5)V(c6)V(c7)V(c8)V(c9)
V(d0)V(d1)V(d2)V(d3)V(d4)V(d5)V(d6) virtual Data* get(); };
struct App { char pad[0xec]; unsigned flags; };
struct Mgr { Obj* o[7]; };
struct Self {
    char pad0[0xd4]; unsigned char en;
    char pad1[0x140-0xd5]; int v140[7];
    char pad2[0x1b8-0x15c]; int start;
    char pad3[0x1c4-0x1bc]; int lim; int cur;
    char pad4[0x1e1-0x1cc]; unsigned char flag;
    char pad5[0x1ec-0x1e2]; int cnt[7];
};
extern App* g_gfApplication;
extern Mgr* g_stLoaderManager;
extern "C" void fn_27_23E34C(Obj*);
extern "C" void fn_27_24CA7C(Self*, int);

extern "C" int fn_27_24C91C(Self* s) {
    if (s->en == 0 || (g_gfApplication->flags >> 27) != 0) return 0;
    if (s->cur != 0 && s->cur <= s->lim) return 1;
    fn_27_24CA7C(s, 0);
    for (int i = s->start; i < 7; i++) {
        int c = s->cnt[i];
        if (c != 0 && c < 0x1869F) {
            s->cnt[i] = c + 1;
            if (s->flag != 0 && s->cnt[i] == s->v140[i] + 10) {
                Obj* o = g_stLoaderManager->o[i];
                if (o != 0) {
                    Data* d = o->get();
                    if (d->a < 0x2e || d->a > 0x31) {
                        if (d->b != 3) {
                            d->b = 3;
                            s->v140[i] += s->cnt[i] + 0x3c;
                        }
                    } else fn_27_23E34C(o);
                }
            }
        }
    }
    return 0;
}