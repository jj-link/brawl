#include <string.h>

#pragma force_active on

struct Elem {
    unsigned int type;
    unsigned int value;
};

struct Obj {
    unsigned int a, b, c;
    unsigned int pad[35];
    struct Elem elems[8];
};

extern int fn_802117B8(unsigned int, unsigned int, struct Elem *, int *);

int fn_801E3E20(struct Obj *obj, int *out1, unsigned int *out2)
{
    int count;
    int scalar;
    struct Elem arr[8] __attribute__((aligned(32)));
    struct Obj objcopy __attribute__((aligned(32)));
    int result;
    int index;

    scalar = 0;
    count = 0;

    if (((unsigned int)obj & 0x1F) != 0) {
        memcpy(&objcopy, obj, 0xD8);
        obj = &objcopy;
    }

    result = fn_802117B8(obj->b, obj->c, 0, &scalar);
    if (result > 0)
        goto scan;

    switch (result) {
    case 0:
        if (scalar != 0) {
            result = fn_802117B8(obj->b, obj->c, arr, &scalar);
            switch (result) {
            case 0:
                break;
            default:
                goto scan;
            }
        }
        break;
    default:
        goto scan;
    }

scan:
    if (result == 0) {
        for (index = 0; index < 8; index++) {
            if (obj->elems[index].type == 1) {
                *out1 = 1;
                if (scalar == 0) {
                    *out2 = obj->elems[index].value;
                    return result;
                }
                {
                    unsigned int prev = arr[index].value;
                    if (prev >= obj->elems[index].value)
                        *out2 = 0;
                    else
                        *out2 = obj->elems[index].value - prev;
                }
                return result;
            }
            if (obj->elems[index].type != 0)
                count = index + 1;
        }

        if (count == 0) {
            *out1 = 0;
            *out2 = 0xFFFFFFFF;
        } else {
            count--;
            if (obj->elems[count].type == 4) {
                unsigned int val;
                *out1 = 4;
                *out2 = obj->elems[count].value;
                if (scalar != 0)
                    *out2 = *out2 - arr[count].value;
            } else {
                *out1 = 9;
            }
        }
    }
    return result;
}
