#pragma force_active on
struct FnA1F8Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
int fn_71_A1F8(FnA1F8Obj *obj)
{
    unsigned int x = obj->flags;
    return (int)(((x << 8) | (x >> 24)) & 0xF8000000u) >> 28;
}
}
