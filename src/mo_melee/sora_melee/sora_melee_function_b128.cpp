#include <types.h>
#pragma force_active on

class soModelVirtualNode {
public:
    u32 isNode(u32 n) const;
};

class soModelModuleSimple {
public:
    u32 getNodeNum() const;
};

class ArrIf {
public:
    virtual void v0();
    virtual soModelVirtualNode* at(s32 i);
    virtual void v2();
    virtual s32 size();
};

class soModelModuleImpl {
public:
    char pad[0x90];
    ArrIf* m_arr;
    bool isNode(u32 arg0);
};

bool soModelModuleImpl::isNode(u32 arg0) {
    if (arg0 + 0x10000 != 0xFFFF) {
        s32 n = m_arr->size();
        for (s32 i = 0; i < n; i++) {
            if (m_arr->at(i)->isNode(arg0) == 1) {
                return true;
            }
        }
        if (arg0 < ((const soModelModuleSimple*)this)->getNodeNum()) {
            return true;
        }
    }
    return false;
}
