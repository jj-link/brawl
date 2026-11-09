#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
void* fn_8004D138(void*, int);
void fn_803F8ACC(void*, unsigned int, unsigned int, void*);
int fn_2_2AB44(const void*, const void*);
int isCharUsable__6muMenuFiii(int);
}
extern "C" void fn_2_2A97C(void* self, int arg1) {
    unsigned int list[0x23][2];
    int count = 0;
    int i;
    int j;
    unsigned int* base = (unsigned int*)fn_8004D138(g_GameGlobal, arg1);
    count = 0;
    for (i = 0; i < 0x23; i++) {
        if (isCharUsable__6muMenuFiii(i)) {
            list[count][0] = i;
            list[count][1] = base[0x15 + i];
            count++;
        }
    }
    fn_803F8ACC(list, count, 8, (void*)fn_2_2AB44);
    *(int*)((char*)self + 0x6a8) = 0x23;
    *(int*)((char*)self + 0x6ac) = 0x23;
    *(int*)((char*)self + 0x6b0) = 0x23;
    if (count > 0 && list[0][1] != 0) {
        if (count > 1) {
            if (list[0][1] != list[1][1]) {
                *(int*)((char*)self + 0x6a8) = list[0][0];
            }
        } else {
            *(int*)((char*)self + 0x6a8) = list[0][0];
        }
    }
    if (*(int*)((char*)self + 0x6a8) != 0x23) {
        for (j = 1; j < count; j++) {
            if (list[j - 1][1] != list[j][1]) break;
        }
        if (j < count) {
            if (list[j][1] != 0) {
                if (count > j + 1) {
                    if (list[j][1] != list[j + 1][1]) {
                        *(int*)((char*)self + 0x6ac) = list[j][0];
                    }
                } else {
                    *(int*)((char*)self + 0x6ac) = list[j][0];
                }
            }
        }
    }
    if (count > 1) {
        if (list[count - 1][1] != list[count - 2][1]) {
            *(int*)((char*)self + 0x6b0) = list[count - 1][0];
        }
    } else {
        *(int*)((char*)self + 0x6b0) = list[count - 1][0];
    }
}