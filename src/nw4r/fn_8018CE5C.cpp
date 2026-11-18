#include <types.h>
#include <string.h>
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

template <typename T>
class ResCommon {
public:
    T* mpData;
    T* ptr() const { return mpData; }
    T& ref() const { return *mpData; }
    template <typename U>
    const U* ofs_to_ptr(s32 ofs) const {
        const u8* p = (const u8*)mpData;
        if (ofs != 0) {
            return (const U*)(p + ofs);
        }
        return 0;
    }
};

class ResDic : public ResCommon<ResDicData> {
};

extern "C" const ResDicNodeData* fn_8018CE5C(const ResDic* self, const char* pName, u32 len) {
    const ResDicData& r = self->ref();
    const ResDicNodeData* pNode = &r.data[0];
    const ResDicNodeData* pChild = &r.data[pNode->idxLeft];
    while (pNode->ref > pChild->ref) {
        pNode = pChild;
        u32 pos = pChild->ref >> 3;
        u32 bit = pChild->ref & 7;
        if (pos < len && ((pName[pos] >> bit) & 1)) {
            pChild = &r.data[pChild->idxRight];
        } else {
            pChild = &r.data[pChild->idxLeft];
        }
    }
    if (pChild->ofsString != 0 && strcmp(pName, self->ofs_to_ptr<char>(pChild->ofsString)) == 0) {
        return pChild;
    }
    return 0;
}
