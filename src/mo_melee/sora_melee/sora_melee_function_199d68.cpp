#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
} FlagsObj;

extern "C" {
void fn_27_199D68(FlagsObj* obj, u32 v) {
    obj->b = v;
}
}
