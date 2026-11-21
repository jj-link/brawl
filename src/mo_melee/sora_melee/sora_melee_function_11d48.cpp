#include <types.h>
#pragma force_active on

struct Elem {
    char pad[0x80];
    f32 f80;
};

struct Set {
    Elem** arr;
    s32 count;
    char pad[0x55 - 8];
    u8 flag;
};

struct Pair {
    Set* a;
    Set* b;
};

struct Owner {
    char pad[0x2c];
    Pair* pair;
};

extern "C" void fn_27_11D48(Owner* arg0, f32 arg1) {
    Set* b;
    s32 i;
    s32 offset;
    Pair* p = arg0->pair;
    if (p != 0) {
        s32 n = p->a->count;
        i = 0;
        offset = 0;
        for (; i < n; offset += 4, i++) {
            Set* a = p->a;
            if (a->flag == 0 && i == a->count - 1 && a->flag != 0 && i != 0) {
                (*(Elem**)((char*)a->arr + offset))->f80 = arg1;
            }
            b = p->b;
            if (b->flag == 0 && i == b->count - 1 && b->flag != 0 && i != 0) {
                (*(Elem**)((char*)b->arr + offset))->f80 = arg1;
            }
        }
    }
}
