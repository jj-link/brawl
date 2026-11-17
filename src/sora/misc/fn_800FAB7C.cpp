#include <ut/ut_list.h>
#pragma force_active on

class GameNode : public utListNode {
public:
    void* data;
    virtual int v0();
};

extern "C" u8 lbl_8049E550[];

#pragma opt_propagation off
extern "C" int fn_800FAB7C() {
    GameNode* n = *(GameNode**)lbl_8049E550;
    GameNode* end = 0;
    while (n != end) {
        if (n->v0() == 0) {
            return 0;
        }
        n = (GameNode*)n->m_next;
    }
    return 1;
}
#pragma opt_propagation reset
