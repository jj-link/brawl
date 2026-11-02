#include <nw4r/ut/ut_LinkList.h>
#include <types.h>
#pragma force_active on

struct Elem {
    u8 pad0[0x40];
    s32 val;                     // 0x40
    u8 pad1[0x30];
    u8 byte;                     // 0x74
    u8 pad2[0x5B];
    nw4r::ut::LinkListNode node; // 0xD0
};

static inline s32 clampv(s32 v) {
    if (v > 0x7f) {
        return 0x7f;
    }
    if (v < 0) {
        return 0;
    }
    return v;
}

extern "C" void* fn_801BF63C(nw4r::ut::LinkList<Elem, 0xD0>* list) {
    s32 best = 0x80;
    void* result = 0;
    for (nw4r::ut::LinkList<Elem, 0xD0>::Iterator it = list->GetBeginIter();
         it != list->GetEndIter(); ++it) {
        s32 c = clampv((s32)(*it).byte + (*it).val);
        if (best > c) {
            result = &*it;
            best = c;
        }
    }
    return result;
}
