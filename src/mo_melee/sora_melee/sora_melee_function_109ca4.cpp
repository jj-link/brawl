#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;
typedef int s32;

class ftOwner {
public:
    s32 getStockCount();
};

struct ftEntry {
    u8 pad[0x11];
    u8 unused : 6;
    u8 flag : 1;
    u8 other : 1;
};

class ftEntryManager {
public:
    u8* getEntity(u32 id);
};

extern "C" u32 fn_27_109CA4(u8* self, u32 param) {
    if (self[0x6a] == 1) {
        u8* entry = ((ftEntryManager*)*(u32*)(self + 0x154))->getEntity(param);
        s32 idx = *(s32*)(entry + 0x50);
        if (idx != -1) {
            ftEntry* entry2 = (ftEntry*)((ftEntryManager*)*(u32*)(self + 0x154))->getEntity(idx);
            bool flag = entry2->flag;
            if (flag == 1) {
                ftOwner* owner = *(ftOwner**)(entry + 0x28);
                if (owner->getStockCount() > 0) {
                    return idx;
                }
            }
        }
    }
    return param;
}
