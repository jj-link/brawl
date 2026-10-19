#include <types.h>
#pragma force_active on

struct GameWatchEntry {
    u32 storage[2];
};

struct GameWatchWork {
    u32 header;
    GameWatchEntry entries[2];
};

extern "C" void fn_27_57ED8(GameWatchEntry* entry, void* argument);

extern "C" void fn_107_C390(GameWatchWork* work, void* argument) {
    for (int i = 0; i < 2; i++)
        fn_27_57ED8(&work->entries[i], argument);
}
