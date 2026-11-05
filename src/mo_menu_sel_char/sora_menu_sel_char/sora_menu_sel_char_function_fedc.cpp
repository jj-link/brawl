#include <types.h>
#include <cstdio>

#pragma force_active on

extern "C" {
unsigned int fn_10_B398(void*, int, int, int, int);
unsigned int fn_10_FDDC(void*, char*, unsigned int, int);
void fn_800B92D8(void*, unsigned long, char*, unsigned long);

extern char lbl_10_data_1C8[];
extern float lbl_10_rodata_454;
extern float lbl_10_rodata_510;

void dispHighScore__13muSelCharTaskFiii(
    void* self, int index, unsigned int score, int type
) {
    const char* fmt = lbl_10_data_1C8;
    char buf[64];
    int len = 0;
    int i;
    int a = 0, b = 0, c = 0, d = 0;

    if (index == 3 && type == 1) {
        for (i = 0; i < 35; i++) {
            unsigned int v = fn_10_B398(
                self, i, *(int*)((char*)self + 0x5e0), 0, 0
            );
            unsigned int h, m, s, f;

            if (v < 21600000U) {
                h = v / 216000;
                v %= 216000;
                m = v / 3600;
                v %= 3600;
                s = v / 60;
                v %= 60;
                f = v * 100 / 60;
            } else {
                h = 99;
                m = 59;
                s = 59;
                f = 99;
            }

            a += h;
            b += m;
            c += s;
            d += f;
        }

        c += d / 100;
        d %= 100;
        b += c / 60;
        c %= 60;
        a += b / 60;
        b %= 60;

        if (a >= 100) {
            a = 99;
            b = 59;
            c = 59;
            d = 99;
        }

        if (a > 0)
            len = sprintf(buf, fmt + 0x540, a);

        if (a > 0)
            len += sprintf(buf + len, fmt + 0x548, b);
        else
            len += sprintf(buf + len, fmt + 0x540, b);

        sprintf(buf + len, fmt + 0x550, c, d);
    } else {
        switch (type) {
        case 1: {
            int m, s, f, h;
            if (score < 21600000U) {
                unsigned int v = score;
                h = v / 216000;
                v %= 216000;
                m = v / 3600;
                v %= 3600;
                s = v / 60;
                v %= 60;
                f = v * 100 / 60;
            } else {
                h = 99;
                m = 59;
                s = 59;
                f = 99;
            }

            if (h > 0)
                len = sprintf(buf, fmt + 0x540, h);

            if (h > 0)
                len += sprintf(buf + len, fmt + 0x548, m);
            else
                len += sprintf(buf + len, fmt + 0x540, m);

            sprintf(buf + len, fmt + 0x550, s, f);
            break;
        }

        case 2: {
            float v = (float)score / lbl_10_rodata_454;
            if (v > lbl_10_rodata_510)
                v = lbl_10_rodata_510;
            sprintf(buf, fmt + 0x55c, v);
            break;
        }

        case 4:
            if (score > 999)
                score = 999;
            sprintf(buf, fmt + 0x564, score);
            break;

        default:
            if (score > 999999999U)
                score = 999999999U;
            sprintf(buf, fmt + 0x564, score);
            break;
        }
    }

    fn_800B92D8(
        *(void**)((char*)self + 0x5c4),
        index,
        buf,
        fn_10_FDDC(self, buf, 64, type)
    );
}
}
