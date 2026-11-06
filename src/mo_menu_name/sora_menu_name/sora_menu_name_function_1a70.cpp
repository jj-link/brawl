#include <gm/gm_global.h>
#include <cstring>
#pragma force_active on
extern "C" int getLanguage__10GameGlobalFv(GameGlobal*);
extern "C" int fn_16_1BA0(const char*, const char*, int, int, int);
extern "C" {
extern const char* lbl_16_data_3258;
extern const char* lbl_16_data_329C;
extern const char* lbl_16_data_32AC;
extern const char* lbl_16_data_32BC;
extern const char* lbl_16_data_3300;
extern const char* lbl_16_data_3304;
extern const char* lbl_16_data_327C[];
extern const char* lbl_16_data_32E0[];

int fn_16_1A70(const char* name) {
    const char** list;
    const char* second;
    const char* third;
    const char* first;
    if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
        first = lbl_16_data_3258;
        list = lbl_16_data_327C;
        second = lbl_16_data_329C;
        third = lbl_16_data_32AC;
    } else {
        first = lbl_16_data_32BC;
        list = lbl_16_data_32E0;
        second = lbl_16_data_3300;
        third = lbl_16_data_3304;
    }
    if (strcmp(first, name) == 0) return 0;
    if (fn_16_1BA0(name, second, 2, 1, 0x20) == 0) return 0;
    if (fn_16_1BA0(name, third, 2, 1, 0x20) == 0) return 0;
    while (*list != 0) {
        if (strcmp(*list, name) == 0) return 0;
        list++;
    }
    return 1;
}
}