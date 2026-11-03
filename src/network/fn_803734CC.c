#include <string.h>
#pragma force_active on

extern char lbl_8048FBB8[];
extern int rand(void);

static inline int fn_check(unsigned char *in)
{
    unsigned int parity = 0;
    int i;

    for (i = 1; i < 0x20; i++) {
        parity = (in[0] & 1) ^ (parity ^ ((i ^ in[i - 1]) & 1)) ^
                 (0x4F > in[0] ? 1 : 0) ^
                 (in[i - 1] < in[0] ? 1 : 0);

        if ((parity != 0 && (in[i] & 1) == 0) ||
            (parity == 0 && (in[i] & 1) == 1)) {
            return 0;
        }
    }

    return 1;
}

char *fn_803734CC(char *out, unsigned char *in)
{
    int len;
    int valid;
    int seed;
    int n;

    len = strlen(lbl_8048FBB8);
    valid = fn_check(in);
    n = 0;
    seed = 0;

    do {
        if (valid == 0 || n == 0 || n == 0xD) {
            out[n] = (char)(rand() % 93 + 0x21);
        } else {
            signed char val;
            int byte;
            int value;

            if (n == 1 || n == 0xE) {
                val = (signed char)in[n];
            } else {
                val = (signed char)in[n - 1];
            }

            byte = in[n];
            value = (signed char)lbl_8048FBB8[(n + byte) % len] + n * byte;
            value = in[value % 32] ^
                    (signed char)lbl_8048FBB8[((int)val * seed) % len];

            out[n] = (char)(__abs(value) % 93 + 0x21);
        }

        n++;
        seed += 0x4647;
    } while (n < 0x20);

    return out;
}
