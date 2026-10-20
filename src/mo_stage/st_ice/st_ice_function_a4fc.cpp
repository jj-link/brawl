#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 hi : 4;
    u32 f : 2;
    u32 lo : 26;
};

extern "C" void fn_62_A4FC(struct Flags *obj, u32 value)
{
    struct Flags *p = obj;
    ((struct Flags *)((char *)p + 8))->f = value;
}
