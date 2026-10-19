#include <types.h>
#pragma force_active on

extern "C" void fn_117_21BA0(void* entry, void* argument);

struct DededeFlagPair {
    u8 pad[5];
    u8 flag : 1;
    u8 pad2 : 7;
    u8 clear;
};

extern "C" s32 fn_117_21B50(void* unused, DededeFlagPair* entry, void* argument) {
    bool f = entry->flag;
    if (f == true && entry->clear == 0) {
        fn_117_21BA0(entry, argument);
    }
    return 1;
}
