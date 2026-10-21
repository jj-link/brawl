#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad0[8];
    u8 *flagObj;
    u8 pad1[4];
    u8 *arr[5];
    unsigned int count;
    u8 f28;
    u8 f29;
};

extern "C" void fn_27_234BD0(Obj *o)
{
    unsigned int r6 = 1;
    unsigned int r7 = 0;
    unsigned int r8 = 1;
    unsigned int r9 = 0;
    unsigned int i;

    for (i = 0; i < o->count; i++) {
        if (*o->arr[i] == 1) {
            r7 = 1;
            r8 = 0;
        } else {
            r6 = 0;
            r9 = 1;
        }
    }

    if (o->f28 != 0) {
        if (o->f29 == 0) {
            r8 = r6;
        }
    } else {
        if (o->f29 == 0) {
            r9 = r7;
        }
        r8 = r9;
    }

    if (r8 != 0) {
        *o->flagObj = 1;
    }
}
