#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

class cmSubject {
public:
    nw4r::ut::LinkListNode m_node; // offset 0
    u32 m_flags;                   // offset 8
};

extern nw4r::ut::LinkList<cmSubject, 0> lbl_8049DEDC;

class cmSubjectList {
public:
    static cmSubject* getSubjectByPlayerNo(u32 playerNo);
};

cmSubject* cmSubjectList::getSubjectByPlayerNo(u32 playerNo) {
    u32 flags;
    cmSubject* result = 0;
    nw4r::ut::LinkList<cmSubject, 0>::Iterator it = lbl_8049DEDC.GetBeginIter();
    for (; it != lbl_8049DEDC.GetEndIter(); it++) {
        flags = it->m_flags;
        u8 kind = (u8)(((flags >> 26) & 7) + 254);
        if (kind <= 1) {
            if (playerNo == ((flags >> 20) & 7)) {
                result = &*it;
                break;
            }
        }
    }
    return result;
}
