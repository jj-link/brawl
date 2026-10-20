#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 5;
        u32 field : 5;
        u32 lo : 22;
    } unk8;
} fn_27_199AE8_obj;

extern "C" void fn_27_199AE8(fn_27_199AE8_obj *obj, u32 val) {
    obj->unk8.field = val;
}
