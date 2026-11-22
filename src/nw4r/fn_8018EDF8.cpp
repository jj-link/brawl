#include <nw4r/g3d/g3d_resmdl.h>
#include <types.h>
#pragma force_active on

struct ResDicNodeData {
    u16 ref;
    u16 flag;
    u16 idxLeft;
    u16 idxRight;
    s32 ofsString;
    s32 ofsData;
};
struct ResDicData {
    u32 size;
    u32 numData;
    ResDicNodeData data[1];
};
class ResDic : public nw4r::g3d::ResCommon<ResDicData> {
public:
    ResDic(void* p) : ResCommon<ResDicData>(p) {}
    void* operator[](int idx) const {
        if (IsValid()) {
            s32 ofs = ref().data[idx + 1].ofsData;
            const u8* p = (const u8*)ptr();
            if (ofs != 0) return (void*)(p + ofs);
            return 0;
        }
        return 0;
    }
};
static ResDic GetDic(void* base, s32 ofs) {
    if (ofs != 0) return ResDic((u8*)base + ofs);
    return ResDic((void*)0);
}
namespace nw4r { namespace g3d {
ResNode ResMdl::GetResNode(u32 idx) const {
    void* result = GetDic(ptr(), *(s32*)((u8*)ptr() + 0x14))[idx];
    return *(ResNode*)&result;
}
}}
