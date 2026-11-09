#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E8E70(s32 flag);

extern char* g_ftEntryManager;

class ArrVec {
public:
    virtual void v0();
    virtual void* at(s32 index);
    virtual void v2();
    virtual s32 size();
};

struct EntryMgr {
    char pad[8];
    ArrVec arr;
};

extern "C" void fn_27_124754(void) {
    EntryMgr* mgr = (EntryMgr*)g_ftEntryManager;
    u32 hits = 0;
    s32 count = mgr->arr.size();
    for (s32 i = 0; i < count; i++) {
        void* p = mgr->arr.at(i);
        u8* y = *(u8**)((*(u8**)p) + 0x2c);
        u32 flag = 0;
        if (((*(y + 0) >> 7) & 1) && *(8 + y) != 0) {
            flag = 1;
        }
        if (flag) {
            hits++;
        }
    }
    if (!(!(!(!(!hits))))) {
        fn_27_1E8E70(0);
    } else {
        fn_27_1E8E70(1);
    }
}
