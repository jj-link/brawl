#include <revolution/OS/OSError.h>
#pragma force_active on

extern int fn_801E3E20(void *, int *, unsigned int *);
extern char lbl_80467A98[];
extern char lbl_80467AC0[];

int fn_801D9A90(void *arg0, unsigned int arg1)
{
    unsigned int value;
    int type;

    void *ptr;
    unsigned int index;
    unsigned int best_index;
    int found;
    unsigned int best_count;
    unsigned int best_value;
    int result;
    int bits;
    int i;
    unsigned int cnt;

    best_index = 0;
    found = 0;
    best_count = 0;
    best_value = 0;

    if (arg0 == 0) {
        OSReport(lbl_80467A98, 0x542, lbl_80467AC0);
        return -0x3F9;
    }

    ptr = arg0;
    index = 0;

    while (index < arg1) {
        result = fn_801E3E20(ptr, &type, &value);
        if (result > 0)
            goto next;
        if (result == 0)
            goto process;
        return result;
process:
        switch (type) {
        case 0:
            cnt = 0;
            if (found == 0) {
                best_index = index;
                found = 1;
            }
            bits = ((unsigned char *)ptr)[0x18] | (((unsigned char *)ptr)[0x19] << 8);
            for (i = 0; i < 16; i++) {
                if (bits & (1 << i)) {
                    cnt++;
                }
            }
            if (cnt > best_count) {
                best_index = index;
                best_count = cnt;
            }
            break;
        case 1:
            if (found == 0 && value > best_value) {
                best_index = index;
                best_value = value;
            }
            break;
        case 9:
            break;
        }
next:
        ptr = (void *)((char *)ptr + 0xD8);
        index++;
    }

    if (found == 0 && best_value == 0) {
        return -1;
    }
    return best_index;
}
