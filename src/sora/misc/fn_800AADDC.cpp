#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

class cmSubject {
public:
    nw4r::ut::LinkListNode m_node;
    u32 m_flags;
};
struct Head {
    u32 count;
    cmSubject head;
};
extern Head lbl_8049DEDC;

extern "C" cmSubject* fn_800AADDC(s32 playerNo) {
    if (playerNo < 0)
        return 0;
    Head* head = &lbl_8049DEDC;
    nw4r::ut::LinkList<cmSubject, 0>* list = (nw4r::ut::LinkList<cmSubject, 0>*)head;
    if (head->count != 0) {
        nw4r::ut::LinkList<cmSubject, 0>::Iterator it = list->GetBeginIter();
        for (; it != list->GetEndIter(); it++) {
            u32 flags = it->m_flags;
            u8 kind = (u8)(((flags >> 26) & 7) + 254);
            if (kind <= 1 && playerNo == (s32)((flags >> 20) & 7))
                return &*it;
        }
    }
    return 0;
}