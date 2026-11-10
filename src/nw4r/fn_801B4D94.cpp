#include <types.h>
#pragma force_active on

extern "C" {
void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* mdl, const char* name);
u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void* mdl);
}
extern int lbl_8059E950;

namespace nw4r { namespace g3d {

struct ResMdlData {
    char pad[0xE8];
    void* nodes;
};

struct ResMdl {
    ResMdlData* mpData;
};

class ScnMdl {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual bool SetAnmObj(int index, void* anmObj);
    virtual void RemoveAnmObj(int index);

    char pad[0xE4 - 0x4];
    u32 mCount;   // 0xE4
    ResMdl mResMdl; // 0xE8
    u32* mFlags;  // 0xEC

    static bool Pushback(void* pSelf, void* anmObj, char* name);
};

bool ScnMdl::Pushback(void* pSelf, void* anmObj, char* name) {
    u32 index;
    u32 id;
    ResMdl mdl1;
    mdl1.mpData = (ResMdlData*)((ScnMdl*)pSelf)->mResMdl.mpData->nodes;
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&mdl1, name);
    if (node != NULL) {
        if (node != NULL) {
            id = *(u32*)((char*)node + 0xC);
        } else {
            id = 0;
        }
    } else {
        id = lbl_8059E950;
    }
    if (!((ScnMdl*)pSelf)->SetAnmObj(((ScnMdl*)pSelf)->mCount, anmObj)) {
        return false;
    }
    index = ((ScnMdl*)pSelf)->mCount - 1;
    ResMdl mdl2;
    mdl2.mpData = (ResMdlData*)((ScnMdl*)pSelf)->mResMdl.mpData->nodes;
    int flag;
    if (id < GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&mdl2) && index < (u32)((ScnMdl*)pSelf)->mCount) {
        flag = 1;
        ((ScnMdl*)pSelf)->mFlags[index] = id;
    } else {
        flag = 0;
    }
    if (flag == 0) {
        if (((ScnMdl*)pSelf)->mCount != 0) {
            ((ScnMdl*)pSelf)->RemoveAnmObj(((ScnMdl*)pSelf)->mCount - 1);
        }
        return false;
    }
    return true;
}

}} // namespace
