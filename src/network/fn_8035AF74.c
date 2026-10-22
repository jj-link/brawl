#include <types.h>
#pragma force_active on

void fn_8035A4FC(int a);
void fn_8035E00C(void *p);

typedef struct Obj {
    int **unk0;
    s32 unk4;
} Obj;

void fn_8035AF74(Obj *arg0) {
    s32 i;

    if (arg0 != 0) {
        for (i = 0; i < arg0->unk4; i++) {
            fn_8035A4FC((int)arg0->unk0[i]);
        }
        fn_8035E00C(arg0->unk0);
        fn_8035E00C(arg0);
    }
}
