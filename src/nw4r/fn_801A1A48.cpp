#include <types.h>
#include <nw4r/g3d/g3d_rescommon.h>
#pragma force_active on

// vtable at 0x8042b6d0 and 0x8042ea48 and 0x80453e48 and more: 1 slots; the object holds the vtable pointer at offset 0x0
class Object_vptr_0 {
public:
    virtual void slot0(s32* out);  // offset 0x8
};

struct Override {
    nw4r::g3d::ResCommon<char> p0;
    nw4r::g3d::ResCommon<char> p4;
    nw4r::g3d::ResCommon<char> p8;
    nw4r::g3d::ResCommon<char> pC;
    nw4r::g3d::ResCommon<char> p10;
    nw4r::g3d::ResCommon<char> p14;
    nw4r::g3d::ResCommon<char> p18;
    nw4r::g3d::ResCommon<char> p1C;
    nw4r::g3d::ResCommon<char> p20;
    nw4r::g3d::ResCommon<char> p24;
    nw4r::g3d::ResCommon<char> p28;
    void* p2C;
    void* p30;
    void* p34;
};

extern "C" {
s32 fn_80191170(void* p);
s32 fn_80191190(void* p);
void* fn_801923B0(void* p);
void fn_80192710(void* p);
void fn_801927E0(void* p);
void fn_801928B0(void* p, s32 k);
void fn_8019DB1C(s32 a);
void fn_8019EB3C(void* p);
void fn_8019F150(void* p);
void fn_8019F1C0(void* p);
void fn_8019F428(void* p);
void fn_8019F574(void* p);
void fn_8019F740(void* p);
void fn_8019F950(void* p);
void fn_8019F9FC(void* p);
void fn_8019FAA8(void* p);
void fn_8019FB60(void* p, void* q);
void fn_8019FD30(void* p, s32 a, s32 b, s32 c, s32 d, void* e, s32 f);
void fn_801A045C(void* p);
void fn_801A04EC(void* p);
void fn_801A0798(void* p);
void fn_801A093C(void* p, s32 a, s32 b);
void fn_801A0E7C(s32 a);
void fn_801A0F7C(s32 a, void* b, void* c, void* d, void* e, void* f);
void fn_801A12AC(s32 a);
void fn_801D50A0();
void fn_801D7AE4(s32 a);
}

extern "C" void fn_801A1A48(void** arg0, nw4r::g3d::ResCommon<char>* arg1, s32 arg2, s32 arg3, u32 arg4, Override* arg5, Object_vptr_0* arg6) {
    struct SlotA4 {
        s32 v;
        u8 pad[0x98];
    };
    SlotA4 spA4;

    void* spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    u8 sp8C[4];
    u8 sp88[4];
    void* sp84;
    void* sp80;
    void* sp7C;
    void* sp78;
    void* sp74;
    void* sp70;
    void* sp6C;
    void* sp68;
    void* sp64;
    void* sp60;
    void* sp5C;
    void* sp58;
    void* sp54;
    void* sp50;
    void* sp4C;
    void* sp48;
    void* sp44;
    void* sp40;
    s32 sp3C;
    void* sp38;
    s32 sp34;
    void* sp30;
    void* sp2C;
    void* sp28;
    void* sp24;
    void* sp20;
    void* sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    void* sp8;

    if ((arg4 & 1) == 0) {
        fn_801D7AE4(0);
        fn_801D50A0();
    }
    if (*arg0 != 0) {
        spA0 = 0;
        if (arg5 == 0 || !arg5->p24.IsValid()) {
            spA0 = (u8*)(*arg0) + 0x1C;
        } else {
            *(nw4r::g3d::ResCommon<char>*)&spA0 = arg5->p24;
        }
        fn_801A0E7C(fn_80191190(&spA0));
        sp84 = spA0;
        fn_8019F150(&sp84);
        if (arg5 == 0 || !arg5->p4.IsValid()) {
            sp80 = (u8*)(*arg0) + 0x140;
            fn_8019F428(&sp80);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp7C = arg5->p4;
            fn_8019F428(&sp7C);
        }
        if (arg5 == 0 || !arg5->p0.IsValid()) {
            sp78 = (u8*)(*arg0) + 0x3C;
            fn_8019F1C0(&sp78);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp74 = arg5->p0;
            fn_8019F1C0(&sp74);
        }
        if (arg5 == 0 || !arg5->p8.IsValid()) {
            sp70 = (u8*)(*arg0) + 0x14;
            fn_8019F574(&sp70);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp6C = arg5->p8;
            fn_8019F574(&sp6C);
        }
        if (arg5 == 0 || !arg5->pC.IsValid()) {
            sp68 = fn_801923B0(arg0);
            fn_8019F740(&sp68);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp64 = arg5->pC;
            fn_8019F740(&sp64);
        }
        if (arg5 == 0 || !arg5->p10.IsValid()) {
            void* b = *arg0;
            s32 o = *(s32*)((u8*)b + 0x38);
            sp60 = o ? (u8*)b + o : 0;
            fn_8019F950(&sp60);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp5C = arg5->p10;
            fn_8019F950(&sp5C);
        }
        if (arg5 == 0 || !arg5->p14.IsValid()) {
            void* b = *arg0;
            s32 o = *(s32*)((u8*)b + 0x38);
            void* r = o ? (u8*)b + o : 0;
            sp58 = (u8*)r + 0x20;
            fn_8019F9FC(&sp58);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp54 = arg5->p14;
            fn_8019F9FC(&sp54);
        }
        if (arg5 == 0 || !arg5->p18.IsValid()) {
            if (arg6 != 0) {
                void* b = *arg0;
                s32 o = *(s32*)((u8*)b + 0x38);
                void* r = o ? (u8*)b + o : 0;
                sp50 = (u8*)r + 0xA0;
                fn_8019FB60(&sp50, arg6);
            } else {
                void* b = *arg0;
                s32 o = *(s32*)((u8*)b + 0x38);
                void* r = o ? (u8*)b + o : 0;
                sp4C = (u8*)r + 0xA0;
                fn_8019FAA8(&sp4C);
            }
        } else if (arg6 != 0) {
            *(nw4r::g3d::ResCommon<char>*)&sp48 = arg5->p18;
            fn_8019FB60(&sp48, arg6);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp44 = arg5->p18;
            fn_8019FAA8(&sp44);
        }
        fn_801A0F7C(fn_80191170(&spA0), &sp9C, &sp98, &sp94, &sp90, sp88);
        sp8C[0] = sp88[0];
        sp8C[1] = sp88[1];
        sp8C[2] = sp88[2];
        sp8C[3] = sp88[3];
        if (arg5 == 0 || !arg5->p1C.IsValid()) {
            typedef nw4r::g3d::ResCommon<char> Word;
            Word color = *(Word*)sp8C;
            s32 enabled;
            if (arg4 & 8)
                enabled = 1;
            else
                enabled = 0;
            s32 a = sp9C;
            void** material = &sp40;
            *(Word*)&sp3C = color;
            s32* colorArg = &sp3C;
            s32 b = sp98;
            u8* base = (u8*)*arg0;
            s32 c = sp94;
            void* data = base + 0x3EC;
            s32 d = sp90;
            *material = data;
            fn_8019FD30(material, a, b, c, d, colorArg, enabled);
        } else {
            typedef nw4r::g3d::ResCommon<char> Word;
            Word color = *(Word*)sp8C;
            s32 enabled;
            if (arg4 & 8)
                enabled = 1;
            else
                enabled = 0;
            s32 a = sp9C;
            void** material = &sp38;
            *(Word*)&sp34 = color;
            s32* colorArg = &sp34;
            s32 b = sp98;
            Word data = arg5->p1C;
            s32 c = sp94;
            *(Word*)material = data;
            s32 d = sp90;
            fn_8019FD30(material, a, b, c, d, colorArg, enabled);
        }
        if (arg5 == 0 || !arg5->p20.IsValid()) {
            void* b = *arg0;
            s32 o = *(s32*)((u8*)b + 0x38);
            void* r = o ? (u8*)b + o : 0;
            sp30 = (u8*)r + 0xE0;
            fn_801A045C(&sp30);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp2C = arg5->p20;
            fn_801A045C(&sp2C);
        }
        if (arg5 == 0 || !arg5->p28.IsValid()) {
            sp28 = (u8*)(*arg0) + 0x1A4;
            fn_801A04EC(&sp28);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp24 = arg5->p28;
            fn_801A04EC(&sp24);
        }
    } else if (arg6 != 0) {
        if (arg5 == 0 || !arg5->p18.IsValid()) {
            spA4.v = 0;
            arg6->slot0(&spA4.v);
            fn_8019EB3C(&spA4.v);
        } else {
            *(nw4r::g3d::ResCommon<char>*)&sp20 = arg5->p18;
            fn_8019FB60(&sp20, arg6);
        }
    }
    if (arg1->IsValid() && !(*(u32*)(arg1->ptr() + 0x34) & 2)) {
        if ((arg4 & 2) == 0) {
            *(nw4r::g3d::ResCommon<char>*)&sp1C = *arg1;
            fn_801A0798(&sp1C);
            if (arg5 != 0) {
                if (arg5->p2C != 0) {
                    sp18 = ((s32*)arg5->p2C)[*(s16*)(arg1->ptr() + 0x48)];
                    fn_80192710(&sp18);
                }
                if (arg5->p30 != 0) {
                    s16 i = *(s16*)(arg1->ptr() + 0x4A);
                    if (i >= 0) {
                        sp14 = ((s32*)arg5->p30)[i];
                        fn_801927E0(&sp14);
                    }
                }
                if (arg5->p34 != 0) {
                    s16 i = *(s16*)(arg1->ptr() + 0x4C);
                    if (i >= 0) {
                        sp10 = ((s32*)arg5->p34)[i];
                        fn_801928B0(&sp10, 0xB);
                    }
                    s16 j = *(s16*)(arg1->ptr() + 0x4E);
                    if (j >= 0) {
                        spC = ((s32*)arg5->p34)[j];
                        fn_801928B0(&spC, 0xC);
                    }
                }
            }
        }
        if (arg4 & 4) {
            fn_8019DB1C(1);
            fn_801A12AC(0x10);
        }
        sp8 = arg1->ptr();
        fn_801A093C(&sp8, arg2, arg3);
    }
}
