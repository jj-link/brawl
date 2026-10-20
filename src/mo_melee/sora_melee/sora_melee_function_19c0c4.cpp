#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    char pad[8];
    u32 hi : 6;
    u32 mid : 3;
    u32 lo : 23;
};

extern "C" {
void fn_27_19C0C4(FlagHolder *obj, u32 value)
{
    obj->mid = value;
}
}
