#pragma force_active on
typedef int s32;

namespace nw4r {
namespace g3d {

class ScnMdl {
public:
    class CopiedVisAccess {
    public:
        CopiedVisAccess(ScnMdl* mdl, unsigned long idx);

        ScnMdl* unk0;
        unsigned long unk4;
        s32 unk8;
    };

    char pad0[0xE8];
    s32 unkE8;
    char padEC[0x5C];
    s32 unk148;
};

}
}

extern "C" s32 GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, unsigned long idx);

nw4r::g3d::ScnMdl::CopiedVisAccess::CopiedVisAccess(nw4r::g3d::ScnMdl* mdl, unsigned long idx) {
    s32 found = 0;
    if (mdl != 0) {
        s32 tmp = mdl->unkE8;
        if (GetResNode__Q34nw4r3g3d6ResMdlCFUl(&tmp, idx) != 0) {
            found = 1;
        }
    }
    if (found != 0) {
        unk0 = mdl;
        unk4 = idx;
        s32 r = mdl->unk148;
        if (r != 0) {
            unk8 = r + idx;
        } else {
            unk8 = 0;
        }
    } else {
        unk4 = idx;
        unk0 = 0;
        unk8 = 0;
    }
}
