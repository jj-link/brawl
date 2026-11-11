#include <types.h>
#include <math.h>
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
    virtual f32 getDir();
    virtual void vf10();
    virtual void vf11();
    virtual f32 getValueF(u32);
    virtual void setValueF(f32, u32);
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual s32 check(u32);
};

extern "C" {
void* fn_41_473DC(void*, s32);
void fn_41_47470(void*, void*, void*);
void fn_41_47544(u8*, void*);
void fn_41_47A2C(void*, void*, u32);
void fn_41_47D8C(void*, u8, void*, void*, void*);
extern f32 lbl_41_rodata_1198;
extern f32 lbl_41_rodata_119C;

s32 fn_41_6595C(void* self, void* acc)
{
    f32 buf[3];
    u8 flag;

    IValueMod* value = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
    void* p = fn_41_473DC(acc, value->getValue(0x10000007));

    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);

    if (*(u32*)((u8*)p + 0xc) == 3) {
        IValueMod* v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
        if (v->check(0x12000006) == 0) {
            v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
            buf[0] = v->getValueF(0x1100000A);
            v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
            buf[1] = v->getValueF(0x1100000B);
            v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
            f32 angle = v->getValueF(0x11000004);
            v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
            f32 dist = v->getValueF(0x1100000D);

            angle = lbl_41_rodata_1198 * angle;
            f32 cosVal = dist * (f32)cos(angle);
            f32 sinVal = dist * (f32)sin(angle);

            IValueMod* other = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x0c);
            if (other->getDir() == lbl_41_rodata_119C) {
                buf[0] += cosVal;
                buf[1] += sinVal;
            } else {
                buf[0] -= cosVal;
                buf[1] -= sinVal;
            }
        }

        v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
        f32 minVal = v->getValueF(0x11000007);
        v = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
        f32 maxVal = v->getValueF(0x11000008);

        if (buf[1] < minVal) buf[1] = minVal;
        if (buf[1] > maxVal) buf[1] = maxVal;

        IValueMod* w = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
        f32 x = buf[0];
        w->setValueF(x, 0x1100000A);
        w = *(IValueMod**)((u8*)*(void**)((u8*)acc + 0xd8) + 0x64);
        w->setValueF(buf[1], 0x1100000B);
    }

    fn_41_47A2C(p, acc, 1);
    fn_41_47D8C(buf, flag, self, p, acc);
    return 0;
}
}