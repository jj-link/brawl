#include <types.h>
#pragma force_active on

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void setFlag(u32);
};

extern "C" {
void* fn_41_473DC(void*, s32);
void fn_41_47470(void*, void*, void*);
void fn_41_47544(u8*, void*);
void fn_41_47B4C(void*, void*, u32);
void fn_41_47D8C(void*, u8, void*, void*, void*);

int fn_41_42CE8(void* self, void* acc)
{
    u32 buf[3];
    u8 flag;
    IValueMod* value =
        *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
    void* p = fn_41_473DC(acc, value->getValue(0x10000007));

    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);

    if (*(u32*)((u8*)p + 0xc) == 4) {
        IValueMod* value =
            *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
        value->setFlag(0x11000004);
        fn_41_47B4C(p, acc, 1);
    } else {
        u32 other[3];
        fn_41_47470(other, p, acc);
    }

    fn_41_47D8C(buf, flag, self, p, acc);

    u32 kind = *(u32*)((u8*)p + 0xc);
    if (kind == 4)
        return 1;
    return kind == 0;
}
}
