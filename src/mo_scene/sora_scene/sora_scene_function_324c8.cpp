#include <gm/gm_global.h>
#pragma force_active on

struct Data {
    char pad0[0xa4];
    int a;
    char pad1[0x60];
    int b;
    char pad2[0x4c];
    int c;
    char pad3[0x14c];
    float total;
    char pad4[0x418];
    unsigned int flags1;
    char pad5[4];
    unsigned int flags2;
};
extern "C" int fn_1_32638(unsigned int);
extern "C" void* fn_80158BE0();
extern "C" float fn_80158D7C(void*, unsigned int, int, int*, int*);
extern float lbl_1_rodata_22C4;
extern float lbl_1_rodata_224C;

extern "C" void fn_1_324C8() {
    int x, y;
    float sum = 0.0f;
    int v;
    for (unsigned int i = 0; i < 0x22; i++) {
        v = fn_1_32638(i);
        sum += fn_80158D7C(fn_80158BE0(), i, v, &x, &y);
    }
    Data* d = (Data*)g_GameGlobal->m_advData;
    if (d->flags2 & 1) {
        if (!((d->flags2 >> 2) & 1) && d->a == 4) d->a = 3;
        if (!((((Data*)g_GameGlobal->m_advData)->flags2 >> 6) & 1) && d->b == 4) d->b = 3;
        if (!((((Data*)g_GameGlobal->m_advData)->flags2 >> 4) & 1) && d->c == 4) d->c = 3;
    }
    d = (Data*)g_GameGlobal->m_advData;
    if ((d->flags1 >> 12) & 1) sum += lbl_1_rodata_224C;
    unsigned int flags = d->flags2;
    if ((flags >> 2) & 1) sum += lbl_1_rodata_224C;
    if ((flags >> 4) & 1) sum += lbl_1_rodata_224C;
    if ((flags >> 6) & 1) sum += lbl_1_rodata_224C;
    d->total = sum;
}