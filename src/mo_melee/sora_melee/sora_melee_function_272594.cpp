#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

struct FnOwner;

extern void* lbl_27_bss_6148;
extern "C" void fn_27_271BA4(FnOwner* self, s32 a1, u32 key, s32 a3, s32 a4);

extern "C" void fn_27_272594(void* arg0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    u8* object = (u8*)arg0;
    void* owner = lbl_27_bss_6148;

    if (object[5] == 0)
        return;
    if (owner == 0)
        return;

    fn_27_271BA4((FnOwner*)owner, a1, object[4], a2, a3);
}
