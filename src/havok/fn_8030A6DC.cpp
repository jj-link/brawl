#include <types.h>
#pragma force_active on

struct Pair {
    u16 key;
    u16 value;
};

extern "C" const int lbl_805332B0[];

extern "C" void fn_8030A6DC(
    Pair **arg0, char *arg1, int count, int extra, int tableIndex, Pair *dst)
{
    int i;
    for (i = 0; i < count; ++i) {
        dst[i] = (*arg0)[i];
    }

    Pair *out = *arg0 + 1;
    Pair *leftEnd = dst + count - 1;
    Pair *left = dst + 1;
    Pair *base = *arg0;
    Pair *right = base + count;
    Pair *rightEnd = base + (count + extra);

    while (left->key < right->key) {
        ++left;
        ++out;
    }

    if (left < leftEnd && right < rightEnd) {
        do {
            if (left->key < right->key) {
                *out = *left++;
                *(u16 *)(lbl_805332B0[tableIndex * 2 + (out->key & 1)] +
                         (int)(arg1 + out->value * 16)) = out - *arg0;
                ++out;
                if (left >= leftEnd) {
                    break;
                }
            } else {
                *out = *right++;
                *(u16 *)(lbl_805332B0[tableIndex * 2 + (out->key & 1)] +
                         (int)(arg1 + out->value * 16)) = out - *arg0;
                ++out;
                if (right >= rightEnd) {
                    break;
                }
            }
        } while (1);
    }

    while (right < rightEnd) {
        *out = *right++;
        *(u16 *)(lbl_805332B0[tableIndex * 2 + (out->key & 1)] +
                 (int)(arg1 + out->value * 16)) = out - *arg0;
        ++out;
    }

    while (left <= leftEnd) {
        *out = *left++;
        *(u16 *)(lbl_805332B0[tableIndex * 2 + (out->key & 1)] +
                 (int)(arg1 + out->value * 16)) = out - *arg0;
        ++out;
    }
}
