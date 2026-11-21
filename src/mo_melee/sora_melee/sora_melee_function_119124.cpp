#include <types.h>
#include <ft/ft_entry.h>
#include <ft/ft_entry_manager.h>
#pragma force_active on

class ftEntryListIface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void push(ftEntry* const& newElement);
};

extern "C" s32 fn_27_119124(ftEntryManager* self, s32 arg1) {
    s32 start = (arg1 == 1) ? 0 : 4;
    s32 count = *(s32*)((char*)self + 4);
    for (s32 i = start; i < count; i++) {
        char* entries = *(char**)self;
        if (*(u8*)(entries + i * 0x244 + 0xF) == 7) {
            ftEntry* ent;
            s32 off2;
            const s32 cnt = *(s32*)((char*)self + 0x38);
            const s32 id = (cnt << 16) | i;
            if ((*(s32*)((char*)self + 0x38) = cnt + 1) > 0xFFFF) {
                *(s32*)((char*)self + 0x38) = 0;
            }
            off2 = i * 0x244;
            ent = (ftEntry*)(*(char**)self + off2);
            ((ftEntryListIface*)((char*)self + 8))->push(ent);
            *(s32*)(*(char**)self + off2 + 4) = id;
            return id;
        }
    }
    return -1;
}
