#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

struct State {
    f32 f0;
    char p4[0x1c];
    u32 u20;
    u32 u24;
    char p28[0x1c];
    u8 b44;
    u8 b45;
};

struct Flags {
    char p0[5];
    u8 enabled : 1;
};

struct Blob {
    u32 id;
    f32 f1;
    f32 f2;
    u8 b0, b1, b2, b3;
};

class Mod {
public:
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(u32, u32);
    virtual Flags* m8(u32);
    virtual void m9(u32);
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16(const void*);
    virtual void m17();
    virtual s32 m18(const void*);
    virtual void m19();
    virtual f32 m20(u32);
    virtual void m21(u32);
    virtual void m22(bool, u32);
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29(s32, u32);
    virtual void m30();
    virtual void m31();
    virtual void m32(const void*, f32);
    virtual void m33();
    virtual u32 m34(u32);
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40(u32, const void*, f32);
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50(u32, u32, u32, u32, f32, f32, f32);
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57(u32, u32, u32, u32);
};

class Damage {
public:
    char pad[8];
    virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5();
    virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17();
    virtual void m18(); virtual void m19(); virtual f32 m20(u32);
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32();
    virtual void m33(); virtual u32 m34(u32);
};

struct Manager { char pad[0x6f]; u8 flag : 1; };
extern "C" {
extern Manager* g_ftManager;
extern f32 lbl_27_rodata_2150;
extern f32 lbl_27_rodata_2154;
}

extern "C" void fn_27_16B150(Mod* self, soModuleAccesser* a) {
    State* st = (State*)((Damage*)a->m_enumerationStart->m_damageModule)->m34((u32)a);
    s32 cmd = ((Mod*)a->m_enumerationStart->m_statusModule)->m18(a->m_enumerationStart);
    ((Mod*)a->m_enumerationStart->m_controllerModule)->m16(a->m_enumerationStart);
    ((Mod*)a->m_enumerationStart->m_controllerModule)->m17();
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m7(0, 0x20000004);
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m7(0, 0x20000001);
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m7(0, 0x20000002);
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m21(0x22000011);
    if ((u32)((st->b45 >> 3) & 1) == 1) {
        ((Mod*)a->m_enumerationStart->m_workManageModule)->m20(0x22000012);
    }
    switch (cmd) {
    case 0x5A: {
        f32 t31 = soValueAccesser::getConstantFloat(a, 0xc80, 0) + (f32)soValueAccesser::getConstantInt(a, 0x5a86, 0);
        Damage* dmg = (Damage*)a->m_enumerationStart->m_damageModule;
        t31 -= dmg->m20(0);
        f32 limit = soValueAccesser::getConstantFloat(a, 0xc81, 0);
        if (limit < limit) limit = -limit;
        Mod* ctl = (Mod*)a->m_enumerationStart->m_controllerModule;
        ctl->m50(0, -1, 0, 0, t31, soValueAccesser::getConstantFloat(a, 0xc82, 0), soValueAccesser::getConstantFloat(a, 0xc83, 0));
        ((Mod*)a->m_enumerationStart->m_controllerModule)->m57(0x1a, 0, 1, -1);
        ((Mod*)a->m_enumerationStart->m_effectModule)->m40(0x1d, a->m_enumerationStart, lbl_27_rodata_2150);
        return;
    }
    case 0x5D: {
        Damage* dmg = (Damage*)a->m_enumerationStart->m_damageModule;
        f32 v = soValueAccesser::getConstantFloat(a, 0xcf4, 0) * dmg->m20(0)
              + (st->f0 * soValueAccesser::getConstantFloat(a, 0xcf3, 0)
              + ((soValueAccesser::getConstantFloat(a, 0xcf0, 0)
              + soValueAccesser::getConstantFloat(a, 0xcf2, 0) * soValueAccesser::getConstantFloat(a, 0xdb2, 0))
              + soValueAccesser::getConstantFloat(a, 0xcf1, 0) * (f32)(3 - soValueAccesser::getConstantInt(a, 0x5a88, 0))));
        if (st->u24 == 0xA) {
            v *= soValueAccesser::getConstantFloat(a, 0xcf7, 0);
        }
        Mod* ctl = (Mod*)a->m_enumerationStart->m_controllerModule;
        ctl->m50(0, 1, 0, 0, v, soValueAccesser::getConstantFloat(a, 0xcf5, 0), soValueAccesser::getConstantFloat(a, 0xcf6, 0));
        ((Mod*)a->m_enumerationStart->m_effectModule)->m40(0x1e, a->m_enumerationStart, lbl_27_rodata_2150);
        return;
    }
    case 0x5F: {
        Damage* dmg = (Damage*)a->m_enumerationStart->m_damageModule;
        f32 t30f = soValueAccesser::getConstantFloat(a, 0xcfc, 0) * dmg->m20(0)
              + (st->f0 * soValueAccesser::getConstantFloat(a, 0xcfb, 0)
              + ((soValueAccesser::getConstantFloat(a, 0xcf8, 0)
              + soValueAccesser::getConstantFloat(a, 0xcfa, 0) * soValueAccesser::getConstantFloat(a, 0xdb2, 0))
              + soValueAccesser::getConstantFloat(a, 0xcf9, 0) * (f32)(3 - soValueAccesser::getConstantInt(a, 0x5a88, 0))));
        Mod* ctl = (Mod*)a->m_enumerationStart->m_controllerModule;
        f32 t31c = soValueAccesser::getConstantFloat(a, 0xcfe, 0);
        ctl->m50(0, 3, 0, 0, t30f, soValueAccesser::getConstantFloat(a, 0xcfd, 0), t31c);
        ((Mod*)a->m_enumerationStart->m_controllerModule)->m57(0xd, 0, 0, -1);
        return;
    }
    default:
        break;
    }
    if ((bool)g_ftManager->flag == true && st->b44 != 0xB) {
        Mod* stat = (Mod*)a->m_enumerationStart->m_statusModule;
        if ((s32)stat->m34(0) != 0xC1) {
            f32 c1 = soValueAccesser::getConstantFloat(a, 0xd2b, 0);
            if (st->f0 >= c1) {
                f32 c2 = soValueAccesser::getConstantFloat(a, 0xd2c, 0);
                s32 v = (s32)(st->f0 * c2);
                if (v > soValueAccesser::getConstantInt(a, 0x5a51, 0)) {
                    v = soValueAccesser::getConstantInt(a, 0x5a51, 0);
                }
                ((Mod*)a->m_enumerationStart->m_collisionHitModule)->m29(v, 0);
            }
        }
    }
    u32 t = st->u24;
    if (t != 3 && t != 0x14) {
        self->m16(a);
        return;
    }
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m20(0x22000013);
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m7(st->u20, 0x20000002);
    Blob blob;
    blob.id = 0xA9;
    blob.f1 = lbl_27_rodata_2150;
    blob.f2 = lbl_27_rodata_2154;
    blob.b0 = 0;
    blob.b1 = 0;
    blob.b2 = 0;
    blob.b3 = 0;
    ((Mod*)a->m_enumerationStart->m_motionModule)->m32(&blob, lbl_27_rodata_2150);
    Flags* f1 = ((Mod*)a->m_enumerationStart->m_kineticModule)->m8(1);
    ((Mod*)a->m_enumerationStart->m_workManageModule)->m22(f1->enabled, 0x22000014);
    Flags* f2 = ((Mod*)a->m_enumerationStart->m_kineticModule)->m8(1);
    f2->enabled = false;
    Flags* f3 = ((Mod*)a->m_enumerationStart->m_kineticModule)->m8(4);
    f3->enabled = false;
    ((Mod*)a->m_enumerationStart->m_situationModule)->m9(1);
}
