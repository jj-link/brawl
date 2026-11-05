#pragma force_active on
#include <internal/mem.h>
typedef unsigned int U32;
typedef unsigned long long U64;
typedef struct {
    U32 count;
    U32 words[64];
} Big;
extern U32 lbl_805349A8[38];
extern U32 fn_8035D770(void);
extern U64 __div2u(U32, U32, U32, U32);
extern int fn_8035ECE0(U32 *, U32, U32 *, U32);
extern void fn_8035F024(U32 *, U32, U32 *, U32, U32 *, U32 *);
extern int fn_8035F370(U32 *, U32, U32 *, U32, U32 *, U32 *, U32);
#define STOP() do { \
    if (lbl_805349A8[27] == 1U) { \
        U32 elapsed = fn_8035D770() - lbl_805349A8[24]; \
        lbl_805349A8[25] += elapsed; \
        lbl_805349A8[27] = 0; \
    } \
} while (0)
int fn_8035FA58(U32 *a, U32 an, U32 *b, U32 bn, U32 unused, U32 *out)
{
    Big product;
    Big q;
    U64 quotient;
    if ((int)lbl_805349A8[27] == 0) {
        lbl_805349A8[26]++;
        lbl_805349A8[24] = fn_8035D770();
        lbl_805349A8[27] = 1;
    }
    if (an > bn) {
        quotient = ((U64)a[an - 1] << 32) | (a[an - 2] & b[bn - 1]);
    } else {
        quotient = a[an - 1];
    }
    quotient /= b[bn - 1];
    memset(&q, 0, sizeof(q));
    q.words[0] = (U32)quotient;
    q.words[1] = (U32)(quotient >> 32);
    if ((U32)(quotient >> 32) != 0) {
        q.words[0] = 0xFFFFFFFF;
        q.words[1] = 0;
    }
    q.count = 1;
    if (fn_8035F370(b, bn, q.words, 1, product.words, &product.count, 64) == 0) {
        STOP();
        return 0;
    }
    while (fn_8035ECE0(product.words, product.count, a, an) == 1) {
        q.words[0] >>= 1;
        if (fn_8035F370(b, bn, q.words, q.count, product.words, &product.count, 64) == 0) {
            STOP();
            return 0;
        }
    }
    fn_8035F024(product.words, product.count, a, an, a, &an);
    *out = q.words[0];
    STOP();
    return 1;
}
