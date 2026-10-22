#include <types.h>
#pragma force_active on

class ObjA {
public:
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void* arg);
};

struct Pad3C {
    char pad[0x3C];
};

class SndObj : public Pad3C {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
};

extern "C" {
    extern void* g_sndSystem;
    extern const f32 lbl_805A2610;

    void fn_800F57F0(void* self, s32 a, s32 b, s32 c, s32 d, s32 e);
    void fn_80075F1C(void* sndSystem, s32 id, s32 param);
    void freeGroup__9sndSystemFii(void* sndSystem, s32 group, s32 param);

    void fn_800F5AEC(void* arg0, s32 arg1) {
        if (*(s32*)((char*)arg0 + 0x88) != 0) {
            fn_800F57F0(arg0, -1, -1, 0, 0, 0);
            s32 st = *(s32*)((char*)arg0 + 0x88);
            if (st == 8 || st == 7 || st == 1 || arg1 != 0) {
                if (st != 0) {
                    char* p = (char*)arg0;
                    for (s32 i = 0; i < 9; i++) {
                        if (*(u8*)(p + 0xA0) != 0) {
                            ObjA* obj = (ObjA*)*(void**)((char*)arg0 + 0x90);
                            void* elem = *(void**)(p + 0x9C);
                            obj->f13(*(void**)((char*)elem + 0x10));
                            *(u8*)(p + 0xA0) = 0;
                        }
                        p += 8;
                    }
                    if (*(s32*)((char*)arg0 + 0x88) == 8) {
                        *(s32*)((char*)arg0 + 0x88) = 0;
                        *(s32*)((char*)arg0 + 0x8C) = 0;
                    }
                }
            } else if (st != 6) {
                *(s32*)((char*)arg0 + 0x88) = 6;
                *(s32*)((char*)arg0 + 0x8C) = 0;
                SndObj* self = (SndObj*)arg0;
                self->v30();
            }
            s32 f41C = *(s32*)((char*)arg0 + 0x41C);
            if (f41C >= 0) {
                fn_80075F1C(g_sndSystem, f41C, 0);
                *(s32*)((char*)arg0 + 0x41C) = -1;
            }
            s32 f418 = *(s32*)((char*)arg0 + 0x418);
            if (f418 >= 0) {
                freeGroup__9sndSystemFii(g_sndSystem, f418, 0);
                *(s32*)((char*)arg0 + 0x418) = -1;
                *(s32*)((char*)arg0 + 0x414) = -1;
                *(s32*)((char*)arg0 + 0x41C) = -1;
                *(f32*)((char*)arg0 + 0x420) = lbl_805A2610;
            }
        }
    }
}
