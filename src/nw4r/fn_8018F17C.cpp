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

template <typename T>
class ResCommon {
public:
    T* mpData;
    ResCommon(void* p) : mpData((T*)p) {}
    ResCommon(const void* p) : mpData((T*)p) {}
    T* ptr() const { return mpData; }
    T& ref() const { return *mpData; }
    bool IsValid() const { return mpData != 0; }
    template <typename U>
    const U* ofs_to_ptr(s32 ofs) const {
        const u8* p = (const u8*)mpData;
        if (ofs != 0) {
            return (const U*)(p + ofs);
        }
        return 0;
    }
    template <typename U>
    U ofs_to_obj(s32 ofs) const {
        u8* p = (u8*)mpData;
        if (ofs != 0) {
            return U(p + ofs);
        }
        return U((void*)0);
    }
};

class ResDic : public ResCommon<ResDicData> {
public:
    ResDic(void* p) : ResCommon<ResDicData>(p) {}
    void* operator[](int idx) const {
        if (IsValid()) {
            return const_cast<void*>(ofs_to_ptr<void>(ref().data[idx + 1].ofsData));
        }
        return 0;
    }
};

struct ResVtxClrData {
    int x;
};

class ResVtxClr : public ResCommon<ResVtxClrData> {
public:
    ResVtxClr(void* p) : ResCommon<ResVtxClrData>(p) {}
};

struct ResXData {
    char pad[0x20];
    s32 toDict;
};

class ResX : public ResCommon<ResXData> {
public:
    ResVtxClr Get(int idx) const;
};

extern "C" ResVtxClr fn_8018F17C(const ResX* self, int idx) {
    return ResVtxClr(self->ofs_to_obj<ResDic>(self->ref().toDict)[idx]);
}
