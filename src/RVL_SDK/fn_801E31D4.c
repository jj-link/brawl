#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct StateFlags {
    u32 checksum;
    u32 data[7];
} StateFlags;

extern StateFlags lbl_804DE220;

extern u32 fn_8020AB58(void *, void *, u32);
extern s32 fn_8020B9BC(const char *, void *, s32);
extern s32 fn_8020BC3C(void *);
extern u32 fn_8020AA78(void *, void *, u32);
extern s32 fn_8020A870(const char *);

static u32 CheckSum(const StateFlags *state) {
    int i;
    const u32 *ptr = (const u32 *)state + 1;
    u32 checksum = 0;

    for (i = 0; i < (sizeof(StateFlags) / sizeof(u32)) - 1; i++) {
        checksum += *ptr++;
    }

    return checksum;
}

static inline s32 WriteState(void *data, u32 size) {
    u8 file[0x90];

    if (fn_8020B9BC("/title/00000001/00000002/data/state.dat", file, 2) == 0) {
        if (fn_8020AB58(file, data, size) != size) {
            fn_8020BC3C(file);
            return 0;
        }
        if (fn_8020BC3C(file) != 0) {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

s32 fn_801E31D4(const StateFlags *state) {
    memcpy(&lbl_804DE220, state, sizeof(StateFlags));
    lbl_804DE220.checksum = CheckSum(&lbl_804DE220);

    return WriteState(&lbl_804DE220, sizeof(StateFlags));
}

s32 fn_801E32B8(void *arg0)
{
    u8 file[0x90];

    if (fn_8020B9BC("/title/00000001/00000002/data/state.dat", file, 1) == 0) {
        u32 got = fn_8020AA78(file, &lbl_804DE220, sizeof(StateFlags));
        fn_8020BC3C(file);
        if (got != sizeof(StateFlags)) {
            fn_8020A870("/title/00000001/00000002/data/state.dat");
            memset(arg0, 0, sizeof(StateFlags));
            return 0;
        }
    } else {
        memset(arg0, 0, sizeof(StateFlags));
        return 0;
    }
    if (CheckSum(&lbl_804DE220) != lbl_804DE220.checksum) {
        memset(arg0, 0, sizeof(StateFlags));
        return 0;
    }
    memcpy(arg0, &lbl_804DE220, sizeof(StateFlags));
    return 1;
}
