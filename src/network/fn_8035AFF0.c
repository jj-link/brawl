#include <types.h>
#pragma force_active on

extern s32 fn_8035A590(s32);

struct Unknown {
    s32 *array;
    s32 count;
};

s32 fn_8035AFF0(struct Unknown *arg0) {
    s32 i;
    s32 sum;

    sum = 0;
    if (arg0 == NULL) {
        return 0;
    }
    i = 0;
    while (i < arg0->count) {
        sum += fn_8035A590(arg0->array[i]);
        i++;
    }
    return sum;
}
