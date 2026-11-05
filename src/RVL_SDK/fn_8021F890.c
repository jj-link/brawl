#include <string.h>
#pragma force_active on

extern void *lbl_804F6810[];

void fn_8021F890(int index, int flag, int arg2) {
    void *state = lbl_804F6810[index];
    unsigned char *data = *(unsigned char **)((char *)state + 0x974);
    int i;
    unsigned int sum;
    sum = 0;
    if (flag == 0) {
        i = 0;
        for (; i < 0x2F; i++) {
            sum += data[i];
        }
        if (data[0x2F] == ((sum + 0x55) & 0xFF)) {
            memcpy(state, data, 0x38);
            *(int *)((char *)state + ((arg2 * 4) & 0x3FC) + 0x38) = 0;
        } else {
            *(int *)((char *)state + ((arg2 * 4) & 0x3FC) + 0x38) = -4;
        }
    }
}
