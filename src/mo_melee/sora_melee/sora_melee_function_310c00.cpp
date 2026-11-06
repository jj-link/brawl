#pragma fp_contract off
#pragma force_active on
#include <so/so_value_accesser.h>
#include <math.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
};

extern "C" {
extern char lbl_27_data_2E430[];
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern float lbl_27_rodata_7460[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_193378(soModuleAccesser*, float);
void fn_27_89DAC(int, soModuleAccesser*);
}

extern "C" void fn_27_310C00(void*, soModuleAccesser* a) {
    const float* c = lbl_27_rodata_7460;
    Vec2f normal;
    switch (a->getStatusModule().getStatusKind()) {
    case 0x114:
        if (a->getSituationModule().getKind() == 2) {
            if (a->getWorkManageModule().getInt(0x20000000) <= 0) {
                void* e = __dynamic_cast(a->getKineticModule().getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
                *(float*)((char*)e + 0x10) = -soValueAccesser::getConstantFloat(a, 0xfb1, 0);
            } else {
                void* e = __dynamic_cast(a->getKineticModule().getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
                *(float*)((char*)e + 0x10) = c[0];
            }
            void* e = __dynamic_cast(a->getKineticModule().getEnergy(3), 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
            Vec2f v;
            v.m_x = soValueAccesser::getConstantFloat(a, 0xfb0, 0);
            v.m_y = c[0];
            *(Vec2f*)((char*)e + 0x20) = v;
        }
        break;
    case 0x117:
        int n = a->getWorkManageModule().getInt(0x20000001);
        if (n > soValueAccesser::getConstantInt(a, 0x5dc7, 0)) {
            void* e = __dynamic_cast(a->getKineticModule().getEnergy(3), 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
            Vec2f v;
            v.m_x = soValueAccesser::getConstantFloat(a, 0xfb5, 0);
            v.m_y = c[0];
            *(Vec2f*)((char*)e + 0x20) = v;
        } else {
            void* e = __dynamic_cast(a->getKineticModule().getEnergy(3), 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
            Vec2f v(c[0], c[0]);
            *(Vec2f*)((char*)e + 0x20) = v;
        }
        {
            float angle = a->getWorkManageModule().getFloat(0x21000004);
            if (a->getSituationModule().getKind() != 2) {
                Vec2f::copy(normal, a->getGroundModule().getTouchNormal((grCollStatus::TouchMask)8, 0));
                float y = normal.m_y;
                angle = (float)atan2(-normal.m_x * a->getPostureModule().getLr(), y);
            }
            fn_27_193378(a, c[2] - c[3] * angle);
            a->getWorkManageModule().setFloat(angle, 0x21000004);
        }
        break;
    case 0x119:
        if (a->getSituationModule().getKind() == 2) {
            soKineticEnergy* e = a->getKineticModule().getEnergy(0);
            if (!e->isEnable()) {
                Vec3f pos(c[0], c[0], c[0]);
                e->resetEnergy(6, &Vec2f(c[0], c[0]), &pos, a);
                *((unsigned char*)e + 5) |= 0x80;
            }
        } else {
            fn_27_89DAC(0, a);
        }
        break;
    }
}
