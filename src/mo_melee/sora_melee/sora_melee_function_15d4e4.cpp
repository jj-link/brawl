#pragma force_active on

#include <types.h>

struct SoraMeleeState {
    char pad0[0x0C];
    float f_0x0C;
    float f_0x10;
    float f_0x14;
    float f_0x18;
    float f_0x1C;
    float f_0x20;
    int i_0x24;
};

struct SoWorld {
    float f_0x00;
    float f_0x04;
};

struct SoModuleEnumeration {
    char pad0[0x64];
    void* m_workManageModule;
};

struct SoModuleAccesser {
    char pad0[0xD8];
    SoModuleEnumeration* m_enumerationStart;
};

struct SoWorkModule {
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
    virtual u32 offFlag(u32 flag);
};

extern "C" {
extern SoWorld* g_soWorld;
extern const float lbl_27_rodata_1F70;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
u32 fn_27_195EA8(void*);
float fn_27_895B4(float, float, float, float);
float fn_27_89794(float, float);
}

extern "C" void fn_27_15D4E4(SoraMeleeState* self, SoModuleAccesser* accesser) {
    float f31 = g_soWorld->f_0x04;

    if (((SoWorkModule*)accesser->m_enumerationStart->m_workManageModule)
            ->offFlag(0x22000002) == 1U) {
        float scale =
            -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xBD7, 0);
        scale *= f31;
        self->f_0x0C = self->f_0x20 * scale;
        return;
    }

    float world_f0 = g_soWorld->f_0x00;
    float f30 = world_f0 * (self->f_0x10 * self->f_0x20);

    if (((SoWorkModule*)accesser->m_enumerationStart->m_workManageModule)
                ->offFlag(0x22000000) == 1U &&
        fn_27_195EA8(accesser) == 1U) {
        if (self->f_0x0C * f30 < lbl_27_rodata_1F70) {
            self->f_0x0C = self->f_0x0C + f30;
        }
    } else {
        if (f30 * (self->f_0x0C + f30) > lbl_27_rodata_1F70) {
            f30 = fn_27_895B4(
                self->f_0x0C,
                f30,
                self->f_0x20 * (self->f_0x14 * f31),
                self->f_0x18);
        }
        self->f_0x0C = self->f_0x0C + f30;
    }

    int mode = self->i_0x24;
    if (mode == -1) {
        return;
    }
    if (self->f_0x1C <= lbl_27_rodata_1F70) {
        return;
    }
    if (mode == 2) {
        self->f_0x0C = fn_27_89794(self->f_0x0C, self->f_0x1C);
        return;
    }
    if (mode == 0) {
        if (self->f_0x0C < lbl_27_rodata_1F70) {
            self->f_0x0C = fn_27_89794(self->f_0x0C, self->f_0x1C);
            return;
        }
    } else if (mode == 1) {
        if (self->f_0x0C > lbl_27_rodata_1F70) {
            self->f_0x0C = fn_27_89794(self->f_0x0C, self->f_0x1C);
        }
    }
}
