#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    char *base;
    u32 count;
};

extern "C" char *fn_27_9A770(FnObj *obj) {
    return obj->base + (obj->count << 4) + 4;
}
