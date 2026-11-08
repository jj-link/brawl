#include <gm/gm_global.h>

#pragma force_active on

extern "C" void fn_10_15A84(void*, int);
extern "C" void fn_10_187C8(void*, int);
extern "C" void fn_10_18E04(void*, int);
extern "C" void fn_10_18E0C(void*, int);

extern "C" void fn_10_95B8(void* self, int index, int value, int selected) {
    char* item = *(char**)((char*)self + 0x44 + index * 4);
    fn_10_15A84(item, value);

    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int valid;
    if (state >= 0 && state < 4)
        valid = 1;
    else
        valid = 0;

    if (valid) {
        selected = *(int*)(item + 0x1c8);
        if (selected >= 0) {
            if (value == 1) {
                if (selected >= 0) {
                    char* other;
                    char* cursor = (char*)self;
                    int i = 0;
                    int count = *(int*)((char*)self + 0x648);

                    for (; i < count; cursor += 4, i++) {
                        if (index != i) {
                            other = *(char**)(cursor + 0x44);
                            if (*(int*)(other + 0x1b4) == 1 &&
                                *(int*)(other + 0x1c8) >= 0 &&
                                selected == *(int*)(other + 0x1c8)) {
                                fn_10_187C8(item, -1);
                                selected = -1;
                                break;
                            }
                        }
                    }

                    if (selected >= 0) {
                        char* cursor = (char*)self;
                        int i = 0;
                        while (i < *(int*)((char*)self + 0x648)) {
                            if (i != index) {
                                char* other = *(char**)(cursor + 0x44);
                                int active;
                                if (*(int*)(other + 0x200) != 0 &&
                                    *(int*)(other + 0x1fc) == 0)
                                    active = 1;
                                else
                                    active = 0;
                                if (active)
                                    fn_10_18E04(other, selected);
                            }
                            cursor += 4;
                            i++;
                        }
                    }
                }
            } else if (selected >= 0) {
                int i = 0;
                char* cursor = (char*)self;
                while (i < *(int*)((char*)self + 0x648)) {
                    if (i != index) {
                        char* other = *(char**)(cursor + 0x44);
                        int active;
                        if (*(int*)(other + 0x200) != 0 &&
                            *(int*)(other + 0x1fc) == 0)
                            active = 1;
                        else
                            active = 0;
                        if (active)
                            fn_10_18E0C(other, selected);
                    }
                    cursor += 4;
                    i++;
                }
            }
        }
    }
}
