#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct HuffEntry {
    u16 length;
    u16 value;
} HuffEntry;

typedef struct HuffTable {
    HuffEntry *lookup;
    HuffEntry *codes;
    u8 *symbols;
    u8 count;
} HuffTable;

s32 fn_80260AA4(u8 *bits, u8 *symbols, HuffTable *arg) {
    int sizes[256];
    int codes[256];
    HuffEntry *lookup = arg->lookup;
    HuffEntry *max = arg->codes;
    u8 *values = arg->symbols;
    u8 count = arg->count;
    {
        u8 *p;
        int *out = sizes;
        int k = 0;
        int length = 1;
        int n = 1;
        p = bits + 1;
        for (;;) {
            if (n > *p) {
                length++;
                n = 1;
                p++;
                if (length > 16) {
                    sizes[k] = 0;
                    break;
                }
            } else {
                k++;
                *out++ = length;
                if (k > count)
                    return -64;
                n++;
            }
        }
    }
    {
        int *p = sizes;
        int k;
        u16 code = 0;
        u8 length = sizes[0];
        k = 0;
        while (*p) {
            u8 l = length;
            while (l == (u8)*p) {
                codes[k++] = code;
                code++;
                p++;
            }
            if (code >= (1 << l))
                return -64;
            code <<= 1;
            length++;
        }
    }
    {
        int i;
        memset(max, 0, 0x44);
        for (i = 0; i < count; i++) {
            u32 s = sizes[i];
            if (s <= 16) {
                max[s].value = i;
                max[s].length = codes[i];
            }
        }
    }
    {
        int *c = codes;
        int count2;
        int k = 0;
        int i;
        int j;
        int n;
        int index;
        for (i = 1; i <= 8; i++) {
            int shift = 8 - i;
            j = 1;
            count2 = 1 << shift;
            for (; j <= bits[i];) {
                index = *c << shift;
                for (n = count2; n > 0; n--) {
                    lookup[index].length = i;
                    lookup[index].value = symbols[k];
                    index++;
                }
                j++;
                c++;
                k++;
            }
        }
    }
    memcpy(values, symbols, count);
    return 0;
}
