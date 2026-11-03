#include <types.h>
#pragma force_active on

// Classes this function calls through, from the game's vtables. Keep every method in this order so
// the vtable offsets come out the same; declare parameters and return types as the code needs.

// vtable at 0x164 and 0x1dc0 and 0x1dc0 and more: 17 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 4
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

// vtable at 0x740: 6 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 4
class Class_740 {
public:
    virtual void fn_41_BDA0();
    virtual void fn_41_BE5C();
    virtual void fn_41_BFDC();
    virtual void fn_41_BDA8();
    virtual void fn_41_C59C();
};

// vtable at 0x808 and 0xe04 and 0xff0 and more: 24 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 4
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

// vtable at 0x6e20: 22 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 4
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
};

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32 id);
};

extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern u8 lbl_41_bss_504[];

extern "C" {
void* fn_41_473DC(void* acc, s32 v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47544(u8* out, void* p);
void fn_41_4768C(void* a, void* p, void* acc, u8 b, s32 c);
void fn_41_47A2C(void* p, void* acc, u32 flag);
void fn_41_47D8C(void* out, u8 flag, void* self, void* p, void* acc);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

static IValueMod* getValueMod(void* acc) {
    void* p = *(void**)((u8*)acc + 0xd8);
    return *(IValueMod**)((u8*)p + 0x64);
}

extern "C" s32 fn_41_404F0(void* self, void* acc) {
    float buf[4];
    u8 flag;
    void* p = fn_41_473DC(acc, getValueMod(acc)->getValue(0x10000007));
    void* en = __dynamic_cast(*(void**)((u8*)acc + 0x8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    if (*(s32*)((u8*)en + 0xac) == 0x20) {
        u32 c = *(u32*)((u8*)p + 0xc);
        if (c == 1) goto body;
        if (c != 2) goto end;
    body:
        {
            u8* base = lbl_41_bss_504;
            base[6] = 0;
            fn_41_4768C(*(void**)(base + 8), p, acc, 0, 0);
        }
    end:;
    }
    fn_41_47A2C(p, acc, 1);
    fn_41_47D8C(buf, flag, self, p, acc);
    return 0;
}
