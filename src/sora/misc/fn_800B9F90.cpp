#pragma force_active on
typedef unsigned int u32;
struct PadStatus {
    u32 words[16];
};
struct PadSys {
    char pad[0x3c];
    unsigned short mask;
};
struct Arg {
    char pad[4];
    unsigned char bits;
};
extern PadSys* g_gfPadSystem;
extern "C" void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(PadSys*, int, PadStatus*);
extern "C" void merge__11gfPadSystemFP11gfPadStatusiP11gfPadStatus(PadStatus*, int, PadStatus*);

extern "C" void fn_800B9F90(PadStatus* out, Arg* a, int flag)
{
    PadStatus buf[8];
    PadStatus res;
    PadStatus* p = buf;
    int n = 0;
    int bit = 1;
    int i = 0;
    unsigned short mask = g_gfPadSystem->mask;
    for (; i < 8; i++) {
        if ((a->bits & bit) && (mask & bit)) {
            getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, i, p);
            if (flag) {
                int t = p->words[15];
                if (t == 3 || (t == 2 && (p->words[1] & 0x40))) {
                    p->words[1] &= ~0xF;
                }
            }
            p++;
            n++;
        }
        bit = (bit << 1) & 0xFE;
    }
    merge__11gfPadSystemFP11gfPadStatusiP11gfPadStatus(buf, n, &res);
    *out = res;
}
