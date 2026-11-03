#include <types.h>
#pragma force_active on

struct ResName {
    void* p;
    ResName(void* x) : p(x) {}
};
struct ResDic {
    void* p;
    ResDic(void* x) : p(x) {}
};
extern "C" int fn_8018D098(ResDic a, ResName b);

template <typename T>
static inline T ofs_to_obj(char* base, s32 off) {
    if (off != 0)
        return T(base + off);
    return T(0);
}

extern "C" {
void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const void* mdl, u32 index);
u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void* mdl);
void fn_8019DA5C(void* self, u32 mask, int flag);

struct Self {
    char pad[0x14];
    s16* map;
    char pad2[0x14];
    char* data;
};

static inline ResName getName(char* n2) {
    s32 off = *(s32*)(n2 + 8);
    if (off != 0)
        return ResName((char*)(n2 + off) - 4);
    return ResName(0);
}

static inline void tryMap(Self* self, void* mdl, u32 index, s32& result) {
    char* n2 = (char*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(mdl, index);
    ResName name = getName(n2);
    ResDic dic = ofs_to_obj<ResDic>(self->data, *(s32*)(self->data + 0x10));
    s32 found = fn_8018D098(dic, name);
    if (found != -1) {
        result = 1;
        self->map[index] = found;
    }
}

static inline u32 getEnd(void* mdlp, u32 index) {
    void* sub = mdlp;
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sub, index);
    void* entry;
    {
        u32 off = *(u32*)((char*)node + 0x64);
        entry = off != 0 ? (char*)node + off : 0;
    }
    while (entry == 0) {
        u32 off = *(u32*)((char*)node + 0x5C);
        node = off != 0 ? (char*)node + off : 0;
        if (node == 0)
            break;
        off = *(u32*)((char*)node + 0x64);
        entry = off != 0 ? (char*)node + off : 0;
    }
    if (entry != 0) {
        if (entry != 0)
            return *(u32*)((char*)entry + 0xC);
        else
            return 0;
    }
    return GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&sub);
}

s32 fn_8019B370(Self* self, void* mdl, u32 index, s32 mode) {
    s32 result = 0;
    switch (mode) {
    case 1: {
        u32 count = getEnd(*(void**)mdl, index);
        for (; index < count; index++) {
            tryMap(self, mdl, index, result);
        }
        break;
    }
    case 0:
        tryMap(self, mdl, index, result);
        break;
    }
    fn_8019DA5C(self, 4, 1);
    return result;
}
}