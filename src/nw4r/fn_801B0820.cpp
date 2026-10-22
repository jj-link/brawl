#pragma force_active on
#include <types.h>

namespace nw4r {
namespace g3d {
namespace ScnMdl {

struct CopiedVisObj {
    char pad[0x13C];
    u32 flags;
};

class CopiedVisAccess {
public:
    CopiedVisObj* unk0;
    u32 pad4;
    u8* unk8;

    bool SetVisibility(bool visible);
};

bool CopiedVisAccess::SetVisibility(bool visible) {
    if (unk0 != 0) {
        if (unk8 != 0) {
            if (visible != 0) {
                if (*unk8 == 0) {
                    unk0->flags = unk0->flags | 1;
                    *unk8 = 1;
                }
            } else {
                if (*unk8 != 0) {
                    unk0->flags = unk0->flags | 1;
                    *unk8 = 0;
                }
            }
            return true;
        }
    }
    return false;
}

}
}
}
