#pragma force_active on
typedef int s32;
typedef unsigned int u32;

enum emKind { emKind_Dummy = 0 };

struct emParam {
    s32 unk0;
    emKind kind;
};

struct emInfo {
    static emInfo* getInstance();
    virtual void vf0();
    virtual u32 vf1(emKind kind);
    s32 (*getCreateFuncPtr(emKind kind))(void*, void*);
};

extern "C" s32 fn_41_70(void* p1, emParam* p2) {
    s32 r;
    if (p2 == 0) {
        return 0;
    }
    if (emInfo::getInstance()->vf1(p2->kind) == 1) {
        return 0;
    }
    emInfo* info = emInfo::getInstance();
    s32 (*fn)(void*, void*) = info->getCreateFuncPtr(p2->kind);
    r = fn(p1, p2);
    if (r == 0) {
        r = 0;
    }
    return r;
}
