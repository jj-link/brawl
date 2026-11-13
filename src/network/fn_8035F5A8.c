#pragma force_active on
#include <internal/mem.h>

typedef unsigned int U32;

typedef struct {
    U32 count;
    U32 words[64];
} Big;

extern U32 lbl_805349A8[38];
extern U32 fn_8035D770(void);
extern int fn_8035ECE0(U32 *, U32, U32 *, U32);
extern int fn_8035FA58(U32 *, U32, U32 *, U32, U32, U32 *);

#define STOP() do { \
    if (lbl_805349A8[23] == 1U) { \
        U32 elapsed = fn_8035D770() - lbl_805349A8[20]; \
        lbl_805349A8[21] += elapsed; \
        lbl_805349A8[23] = 0; \
    } \
} while (0)

int fn_8035F5A8(U32 *arg0, U32 arg1, U32 *b, Big *quot, Big *rem)
{
    U32 an;
    U32 *a;
    Big sp210;
    U32 sp10[128];
    U32 sp8;
    U32 *p;
    int bit;
    U32 *q;
    int i;
    int j;
    U32 *bw;
    int r;
    U32 t;
    U32 bn;
    int done;

    an = arg1;
    a = arg0;
    bit = 0x1f;
    bn = b[0];
    bw = b + 1;
    done = 0;

    if (lbl_805349A8[23] == 0) {
        lbl_805349A8[22]++;
        lbl_805349A8[20] = fn_8035D770();
        lbl_805349A8[23] = 1;
    }

    if (an > 0x40 && quot != 0) {
        return 0;
    }

    p = a + an;
    while (an != 0 && p[-1] == 0) {
        p--;
        an--;
    }

    q = bw + bn;
    while (bn != 0 && q[-1] == 0) {
        q--;
        bn--;
    }

    memcpy(sp10, a, an * 4);
    memset(&sp210, 0, 0x104);

    if (an == 0 || bn == 0) {
        if (quot != 0) {
            quot->words[0] = 0;
            quot->count = 0;
        }
        if (rem != 0) {
            rem->words[0] = 0;
            rem->count = 0;
        }
        STOP();
        if (bn == 0) {
            return 0;
        }
        return 1;
    }

    if (fn_8035ECE0(sp10, an, bw, bn) == -1) {
        if (quot != 0) {
            quot->count = 0;
            quot->words[0] = 0;
        }
        rem->count = an;
        memcpy(rem->words, sp10, an * 4);
        STOP();
        return 1;
    }

    while (!((1u << bit) & bw[bn - 1]) && bit >= 0) {
        bit--;
    }
    if (bit == -1) {
        STOP();
        return 0;
    }

    j = bn;
    i = an - bn;
    bit += (bn - 1) << 5;

    for (;;) {
        r = fn_8035ECE0(&sp10[i], j, bw, bn);
        if (r == -1) {
            if (i > 0) {
                i--;
                j++;
            } else {
                done = 1;
            }
        } else if (r == 0) {
            memset((int *)sp10 + i, 0, j * 4);
            sp210.words[i]++;
            t = i + j;
            if (sp210.count < t) {
                sp210.count = t;
            }
            i -= j;
            j = 1;
            if (i < 0) {
                done = 1;
            }
        } else {
            U32 *cur = &sp10[i];
            sp8 = 0;
            if (fn_8035FA58(&sp10[i], j, bw, bn, bit, &sp8) == 0) {
                STOP();
                return 0;
            }
            sp210.words[i] += sp8;
            t = i + j;
            if (sp210.count < t) {
                sp210.count = t;
            }
            while (cur[j - 1] == 0 && j > 1) {
                j--;
            }
            while (sp10[i + j - 1] == 0 && i > 1) {
                i--;
            }
        }
        if (done) {
            break;
        }
    }

    if (i >= 0) {
        memcpy(rem->words, &sp10[i], j * 4);
        rem->count = j;
    } else {
        rem->words[0] = 0;
        rem->count = 0;
    }

    if (quot != 0) {
        memcpy(quot->words, &sp210.words[0], sp210.count * 4);
        quot->count = sp210.count;
    }

    STOP();
    return 1;
}
