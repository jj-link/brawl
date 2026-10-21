#include <types.h>
#pragma force_active on

extern "C" void fn_27_4AC40(void* p, s32 flag);
extern "C" void fn_27_19C31C(void* obj, s32 a, void* buf, s32 b);
extern "C" void fn_27_4AD20(void* p, s16 flag);
extern "C" void fn_27_4B184(void* a, s32 b, s32 c, u8 d, void* e, void* f, u8 g, u8 h);

extern "C" void* fn_114_96B8(void* obj, s32 p1, s32 p2, s32 p3, void* p4) {
    u8 buf[0x54];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(obj, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184((char*)obj + 0x17c, p1, p2, (u8)p3, obj, p4, 1, 1);
    return obj;
}
