#include <types.h>
#include <mt/mt_trig.h>
#include <so/so_value_accesser.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(u32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual f32 slot9();
    virtual void slot10();
    virtual void slot11();
    virtual f32 slot12(u32);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31(u32, void*);
};

class Base8 { public: u32 pad[2]; };
class Object_vptr_8 : public Base8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(u32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual f32 slot9();
    virtual void slot10();
    virtual void slot11();
    virtual f32 slot12(u32);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31(u32, void*);
};

extern "C" {
void* fn_41_473DC(void*, s32);
void fn_41_47470(void*, void*, void*);
void fn_41_47544(u8*, void*);
f32 fn_41_6AD8(void*, void*);
void fn_41_47A2C(void*, void*, u32);
void fn_41_47C64(void*, void*, void*, void*, u32);
void fn_41_5AC4(void*, f32, f32, f32);
void fn_41_2D2A0(void*, void*, f32, s32, s32, u32, u32, void*, f32, u32, u32);
u32 fn_41_AA74(void*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern u8 lbl_41_bss_504[];
extern f32 lbl_41_rodata_1168[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
}

static inline void finish(void* buf, u8* flag, void* self, char* p, soModuleAccesser* acc, f32 dir) {
    void* enemy = __dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    StageObject* object = *(StageObject**)((char*)acc + 8);
    u32 id = *(u32*)((char*)object + 0x28);
    fn_41_2D2A0(self, buf, dir, soExternalValueAccesser::getTeamNo(object), -1, id,
        fn_41_AA74(enemy, *(u32*)(p + 4)), lbl_41_bss_504, *(f32*)(p + 0x14),
        *flag, (u32)soValueAccesser::getValueFloat(acc, 0x1100000c, 0));
}

#define G(o) (*(f32*)(lbl_41_bss_504 + (o)))

extern "C" s32 fn_41_60C2C(void* self, soModuleAccesser* acc) {
    struct { f32 vB[3]; f32 vA[3]; f32 sc[3]; u32 buf[3]; } frame;
    u8 flag;

    u32 id;
    f32* rod = lbl_41_rodata_1168;
    StageObject* object;
    void* enemy;
    char* p = (char*)fn_41_473DC(acc, (*(Object_vptr_0**)(*(char**)((char*)acc + 0xd8) + 0x64))->slot4(0x10000007));
    fn_41_47470(frame.buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    f32 dir = (*(Object_vptr_0**)(*(char**)((char*)acc + 0xd8) + 0xc))->slot9();

    if (*(u32*)(p + 0xc) == 0) {
        if (*(u32*)(lbl_41_bss_504 + 8) == 0xd)
            dir = rod[0];
        else
            dir = rod[1];
        mtSinCosf(rod[2] * fn_41_6AD8(p + 0x48, acc), &frame.sc[1], &frame.sc[0]);
        f32 t = fn_41_6AD8(p + 0x38, acc);
        G(0x18) = frame.sc[0] * t;
        G(0x1c) = frame.sc[1] * t;
        G(0x20) = frame.sc[0] * *(f32*)(p + 0x58);
        G(0x24) = frame.sc[1] * *(f32*)(p + 0x58);
        G(0x18) *= dir;
        G(0x20) *= dir;
    } else if (*(u32*)(p + 0xc) == 2) {
        frame.vA[0] = (*(Object_vptr_0**)(*(char**)((char*)acc + 0xd8) + 0x64))->slot12(0x1100000a);
        frame.vA[1] = (*(Object_vptr_0**)(*(char**)((char*)acc + 0xd8) + 0x64))->slot12(0x1100000b);
        frame.vA[2] = rod[3];
        fn_41_47C64(p, acc, frame.buf, frame.vA, 0);
    } else {
        fn_41_47A2C(p, acc, 1);
    }
    fn_41_5AC4(frame.vB, rod[3], rod[3], rod[3]);
    (*(Object_vptr_8**)(*(char**)((char*)acc + 0xd8) + 4))->slot31(0x22, frame.vB);
    enemy = __dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    object = *(StageObject**)((char*)acc + 8);
    id = *(u32*)((char*)object + 0x28);
    fn_41_2D2A0(self, frame.buf, dir, soExternalValueAccesser::getTeamNo(object), -1, id,
        fn_41_AA74(enemy, *(u32*)(p + 4)), lbl_41_bss_504, *(f32*)(p + 0x14),
        flag, (u32)soValueAccesser::getValueFloat(acc, 0x1100000c, 0));
    return 0;
}