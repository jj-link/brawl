#include <string.h>
#pragma force_active on

extern char *lbl_804853B8[];
extern char *lbl_80485C40[];

typedef struct {
    char pad[8];
    int count;
} Table;

s32 fn_802781F0(Table *arg0, const char *arg1) {
    s32 count;
    s32 result;
    s32 i;
    s32 j;

    count = arg0->count;
    result = -1;
    for (i = 0; i < count; i++) {
        if (strcmp(arg1, lbl_804853B8[i]) == 0) {
            result = i;
            break;
        }
    }
    for (j = 0; j < 10; j++) {
        if (strcmp(arg1, lbl_80485C40[j]) == 0) {
            result = j + count;
            break;
        }
    }
    return result;
}
