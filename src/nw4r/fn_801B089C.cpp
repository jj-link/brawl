#pragma force_active on
#include <types.h>

namespace nw4r {
namespace g3d {

class ResNode {
public:
    char pad[0x14];
    s32 flags;
};

}
}

struct CopiedVisObj {
    char pad0[0xE8];
    s32 unkE8;
    char pad1[0x50];
    s32 flags;
};

struct CopiedVisAccess {
    CopiedVisObj* unk0;
    s32 unk4;
    u8* unk8;
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, u32 idx);

extern "C" s32 fn_801B089C(CopiedVisAccess* arg0, s32 arg1) {
    u8* temp_r5;
    CopiedVisObj* temp_r6;
    s32 sp8;
    nw4r::g3d::ResNode* temp_r3;

    temp_r6 = arg0->unk0;
    if (temp_r6 != 0) {
        temp_r5 = arg0->unk8;
        if (temp_r5 != 0) {
            if ((arg1 != 0 && *temp_r5 == 0) || (arg1 == 0 && *temp_r5 != 0)) {
                temp_r6->flags = temp_r6->flags | 1;
            }
            *arg0->unk8 = (u8)arg1;
        } else {
            sp8 = temp_r6->unkE8;
            temp_r3 = (nw4r::g3d::ResNode*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp8, arg0->unk4);
            if (temp_r3 != 0) {
                if (arg1 != 0) {
                    temp_r3->flags = temp_r3->flags | 0x100;
                } else {
                    temp_r3->flags = temp_r3->flags & 0xFFFFFEFF;
                }
            }
        }
        return 1;
    }
    return 0;
}
