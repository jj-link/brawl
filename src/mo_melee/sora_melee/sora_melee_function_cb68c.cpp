#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FooStruct {
    char pad[8];
    u32 unk8;
};

extern "C" s32 fn_27_CB68C(FooStruct* p) {
    u32 x = p->unk8;
    return (s32)(((x >> 10) & 0xFF) << 24) >> 25;
}
