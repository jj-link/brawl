#pragma force_active on
#pragma scheduling off

typedef int s32;

struct StageEntry {
    s32 active;
    s32 arg1;
    s32 arg2;
    char padding[0x4C];
};

extern "C" s32 fn_11_7CF0(void* arg0, s32 arg1, s32 arg2) {
    StageEntry* entry = (StageEntry*)((char*)arg0 + 0xC8);
    s32 result = 1;

    if (entry->active != 0) {
        s32 active2 = (++entry)->active;
        result = 2;
        if (active2 != 0) {
            s32 active3 = (++entry)->active;
            result = 3;
            if (active3 != 0) {
                s32 active4 = (++entry)->active;
                result = 4;
                if (active4 != 0) {
                    s32 active5 = (++entry)->active;
                    result = 5;
                    if (active5 != 0) {
                        s32 active6 = (++entry)->active;
                        result = 6;
                        if (active6 != 0) {
                            s32 active7 = (++entry)->active;
                            result = 7;
                            if (active7 != 0) {
                                s32 active8 = (++entry)->active;
                                result = 8;
                                if (active8 != 0) {
                                    result = 9;
                                    ++entry;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (result >= 9)
        return -1;

    entry->active = 1;
    entry->arg1 = arg1;
    entry->arg2 = arg2;
    return result;
}
