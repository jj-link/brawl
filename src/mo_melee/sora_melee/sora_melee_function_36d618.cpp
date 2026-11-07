#pragma force_active on
typedef unsigned int u32;
extern "C" int fn_27_1DAF80(void*, u32);
extern "C" int fn_27_36D618(void* object, u32 flags) {
    if (flags & 6) {
        return 0;
    }
    return fn_27_1DAF80(object, flags);
}