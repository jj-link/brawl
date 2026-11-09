#include <gm/gm_global.h>
#include <gf/gf_pad_system.h>

#pragma force_active on

extern "C" int fn_8004D9A8(GameGlobal*, int);
extern "C" void fn_801104C4(void*);
extern "C" void maskMotor__11gfPadSystemFUs(gfPadSystem*, unsigned int);

struct Entry {
    unsigned char pad[0x1b];
    unsigned char a : 1;
    unsigned char enabled : 1;
    unsigned char rest : 6;
    unsigned char pad2[0x21];
    unsigned char port;
    unsigned char active;
    unsigned char pad3[0x1d];
};

static inline unsigned int getMask(Entry* p)
{
    unsigned int mask = 0;

#pragma unroll 4
    for (int i = 0; i < 4; i++) {
        if (p[i].enabled && p[i].port)
            mask |= 1 << (p[i].port - 1);
    }

    return mask;
}

extern "C" void fn_8011058C(unsigned char* self)
{
    Entry* d;
    unsigned char* c;
    int i;
    unsigned char* original = self;
    Entry* base = (Entry*)(self + 0x98);

    d = base;
    i = 0;
    c = self;
    do {
        if (d != 0) {
            if (c[0x99] != 0 || !((d->active >> 7) & 1) || c[0xd5] == 0) {
                d->enabled = 0;
            } else if (c[0xb0] != 0x78) {
                d->enabled = fn_8004D9A8(g_GameGlobal, c[0xb0]);
            } else {
                unsigned char* rec =
                    (unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap();
                d->enabled = rec[c[0xd5] + 0xf];
            }
        }
        i++;
        d++;
        c += 0x5c;
    } while (i < 4);

    if (original)
        maskMotor__11gfPadSystemFUs(g_gfPadSystem, getMask(base) ^ 0xff);
    else
        maskMotor__11gfPadSystemFUs(g_gfPadSystem, 0xff);

    fn_801104C4(original);
}
