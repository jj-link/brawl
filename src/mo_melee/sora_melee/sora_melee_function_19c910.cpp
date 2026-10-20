#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
} FlagsObj;

extern "C" void fn_27_19C910(FlagsObj* obj, u32 val) {
    obj->f = val;
}
