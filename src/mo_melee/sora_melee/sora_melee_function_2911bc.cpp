#pragma force_active on
typedef unsigned int u32;

struct soraMeleeFlags {
    u32 _0;
    u32 _4;
    u32 mFlags;
};

extern "C" int fn_27_2911BC(soraMeleeFlags* arg) {
    return (arg->mFlags >> 13) & 1;
}
