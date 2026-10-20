#pragma force_active on
typedef struct Obj {
    char pad[0x6c];
    unsigned char flags;
} Obj;

extern "C" void fn_71_2B5C(Obj *p)
{
    p->flags |= 0x8;
}
