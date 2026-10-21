#pragma force_active on
#include <gr/collision/gr_collision_data.h>
#include <types.h>

struct CollHolder {
    u8 pad[8];
    grCollData* m_collData;
};

extern "C" const char* fn_80110CD0(CollHolder* holder, u32 nodeIndex) {
    grCollData* coll = holder->m_collData;
    if (coll == nullptr) {
        return nullptr;
    }
    return coll->getJointNodeName(nodeIndex);
}
