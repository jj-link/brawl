#include <types.h>
#pragma force_active on

struct Class_8758_base { char pad[0x4]; };
class Class_8758 : public Class_8758_base {
public:
    virtual void fn_1_34A04();  // offset 0x8
    virtual void fn_1_34A80();  // offset 0xc
    virtual void fn_1_34DB4();  // offset 0x10
    virtual void fn_1_34DB8();  // offset 0x14
    u32 step;   // 0x08
    s32 step2;  // 0x0C
    u8 b10;     // 0x10
    u8 b11;     // 0x11
    u8 b12;     // 0x12
    u8 b13;     // 0x13
    u8 b14;     // 0x14
    s32 s18;    // 0x18
    s32 s1C;    // 0x1C
    s32 s20;    // 0x20
};

extern "C" {
void fn_1_3D2D8();
s32 fn_80052DB0();
void fn_1_34FA0(Class_8758* self);
void* getInstance__14gfSceneManagerFv();
void setNextScene__14gfSceneManagerFv(void* mgr, const char* name, s32 arg);
void setNextSequence__14gfSceneManagerFv(void* mgr, const char* name, s32 arg);
void fn_800532F0(u32 a, s32 b);
extern const char lbl_1_data_86D0[];
extern char* g_gfApplication;
extern char* g_GameGlobal;
}

extern "C" void fn_1_34A80(Class_8758* self) {
    const char* str = lbl_1_data_86D0;
    char* p;
    void* mgr = getInstance__14gfSceneManagerFv();
    s32 cont = 1;
    while (cont) {
        cont = 0;
        switch (self->step) {
        case 0:
            g_gfApplication[0x110] = 0;
            self->step = 8;
            self->step2 = 1;
            self->b10 = 13;
            cont = 1;
            break;
        case 1:
            fn_1_3D2D8();
            g_gfApplication[0x110] = 0;
            setNextScene__14gfSceneManagerFv(mgr, str + 12, 0);
            *(u8*)(*(char**)(g_GameGlobal + 0x10) + 8) = 1;
            *(u8*)(*(char**)(g_GameGlobal + 0x10) + 4) = 8;
            p = *(char**)(g_GameGlobal + 0x10);
            *(u8*)p = fn_80052DB0() + 1;
            self->step = 2;
            break;
        case 2:
            switch (*(s32*)((char*)mgr + 0x284)) {
            case 0:
                g_gfApplication[0x110] = self->b11;
                setNextSequence__14gfSceneManagerFv(mgr, str + 0x20, 0xa);
                self->step = 0xa;
                break;
            case 1:
                self->step = 3;
                cont = 1;
                break;
            }
            break;
        case 3:
            self->fn_1_34DB8();
            self->step = 8;
            cont = 1;
            self->step2 = 4;
            self->b10 = 10;
            break;
        case 4:
            g_gfApplication[0x110] = self->b11;
            setNextScene__14gfSceneManagerFv(mgr, str + 0x30, 0);
            self->step = 5;
            break;
        case 5: {
            g_gfApplication[0x110] = 0;
            s32 n = (self->b14 != 0) + 1;
            fn_800532F0(*(u32*)(*(char**)(g_GameGlobal + 0x18) + 0x1384) / 60, n);
            switch (*(s32*)((char*)mgr + 0x284)) {
            case 2:
            default:
                self->b12 = 1;
                self->fn_1_34DB8();
                self->step = 4;
                break;
            case 3:
                self->step2 = 6;
                break;
            case 1:
                if (*(u8*)(*(char**)(g_GameGlobal + 0x18) + 0x1378) == 9) {
                    self->step2 = 1;
                    break;
                }
                {
                    s32 t = self->s18 + 1;
                    self->s18 = t;
                    if (self->b13 == 0 && self->b14 == 0 && self->s1C > t) goto d1c;
                    if (self->b13 != 0 || self->b14 != 0 || self->s20 >= 1) goto d14;
                    self->s18 = 0;
                    self->s20 = self->s20 + 1;
                    goto d1c;
                d14:
                    self->step2 = 6;
                    goto d28;
                d1c:
                    self->step = 4;
                    fn_1_34FA0(self);
                }
                break;
            }
        d28:
            if ((s32)self->step != 4) {
                self->step = 8;
                self->b10 = 13;
            }
            cont = 1;
            break;
        }
        case 6:
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x38, 0xd);
            break;
        case 7:
            self->step = 8;
            self->step2 = 1;
            self->b10 = 13;
            cont = 1;
            break;
        case 8:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x48, self->b10);
            self->step = 9;
            break;
        case 9:
            cont = 1;
            self->step = self->step2;
            break;
        }
    }
}
