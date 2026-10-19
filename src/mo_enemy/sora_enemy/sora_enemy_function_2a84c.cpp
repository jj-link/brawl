#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_69748(void* p);

extern "C" void fn_41_2A84C(void* p) {
    fn_27_69748(p);
    *(s32*)((u8*)p + 0x44) = -1;
    *(s32*)((u8*)p + 0x48) = 0;
}
