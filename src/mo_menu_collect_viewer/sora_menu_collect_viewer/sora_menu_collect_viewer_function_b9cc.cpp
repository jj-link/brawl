#include <types.h>
#include <ms/ms_message.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
extern const float lbl_6_rodata_6E8[];
s32 fn_6_A970(char*, s32*, s32*, s32, void*, void*);
void fn_80154B5C(s32, s32, s32, s32);
s32 fn_800BEEB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void fn_800B6838(void*, float*);
void fn_800B798C(void*, float);
}
class Scene {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(void*, void*);
 virtual void f12(); virtual void f13(void*, void*);
};
class Controller {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(float);
};
extern "C" void fn_6_B9CC(char* self) {
    const float* ro = (const float*)((unsigned long)lbl_6_rodata_6E8 | 0);
    u16 buf2[6];
    u16 buf1[6];
    float vec[3];
    s32 a1c;
    s32 a18;
    void* obj;
    Message::utf8to16((wchar_t*)buf1, self + 0x164);
    Message::utf8to16((wchar_t*)buf2, self + 0x179);
    *(s32*)(self + 0x14C) = fn_6_A970(self, &a1c, &a18, *(s32*)(self + 0x264), buf1, buf2);
    fn_80154B5C(*(s32*)(self + 0x130), a18, *(s32*)(self + 0x14C), a1c);
    *(s32*)(self + 0x140) = fn_800BEEB8(3, *(s32*)(*(char**)(self + 0x78) + 4), 0x13,
                                        *(s32*)(self + 0x144), *(s32*)(self + 0x74),
                                        *(s32*)(self + 0x148) + 7, 0, 0x2A,
                                        0x2B, 0, 0, 0xF0);
    obj = *(void**)(self + 0x6C);
    vec[0] = ro[0x70 / 4];
    vec[1] = ro[0xFC / 4];
    vec[2] = ro[0x70 / 4];
    fn_800B6838(obj, vec);
    Scene* scene = *(Scene**)(self + 0x74);
    scene->f11(*(void**)((char*)scene + 0xE4), *(void**)((char*)obj + 0x10));
    ((MuObject*)obj)->setFrameNode(ro[0x70 / 4]);
    fn_800B798C(obj, ro[0x70 / 4]);
    (*(Controller**)(*(char**)((char*)obj + 0x14) + 0xc))->f8(ro[0]);
    (*(Controller**)(*(char**)((char*)obj + 0x14) + 0x14))->f8(ro[0]);
}
