#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

struct fn27_obj {
    char pad[0x40];
    u8 unk40;
    s8 unk41;
};

extern "C" void fn_27_1FAC54(void* p, s32 arg)
{
    fn27_obj* o = (fn27_obj*)p;
    if (arg == 0 && o->unk40 >= 2) {
        return;
    }
    o->unk41 = -1;
    o->unk40 = 0;
}
