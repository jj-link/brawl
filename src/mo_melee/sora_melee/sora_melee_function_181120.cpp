#include <so/so_value_accesser.h>

#pragma force_active on
#pragma fp_contract off

struct Out {
    unsigned short id;
    float x;
    float y;
    unsigned char flag;
};

extern void* lbl_27_bss_5780;
extern int lbl_27_data_30820;
extern float lbl_27_rodata_2440;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" int fn_27_22B3B8(void*, unsigned long, Out*);
extern "C" unsigned int fn_27_196174(soModuleAccesser*, Out*, Vec2f*);
extern "C" void fn_27_195F7C(soModuleAccesser*, Vec3f*);

inline void setPosition(soModuleAccesser* a, float* pos, const float* c) {
    struct { float x, y, z; } p;
    p.x = pos[0]; p.y = pos[1]; p.z = c[0];
    fn_27_195F7C(a, (Vec3f*)&p);
}
inline void doEffect(soModuleAccesser* a, const float* c) {
    Vec3f pos; Vec3f rot;
    pos.m_x = c[0]; pos.m_y = c[0]; pos.m_z = c[0];
    rot.m_x = c[0]; rot.m_y = c[0]; rot.m_z = c[0];
    soEffectModule* effect = a->m_enumerationStart->m_effectModule;
    float scale = soValueAccesser::getConstantFloat(a, 0xbe9, 0);
    effect->reqFollow((EfID)0x5e, 0x12d, &rot, &pos, scale, false, 0, 0, -1);
}
extern "C" void fn_27_181120(void*, soModuleAccesser* a) {
    const float* c = &lbl_27_rodata_2440;

    switch (a->m_enumerationStart->m_statusModule->getStatusKind()) {
    case 0xb6: {
        int prev = a->m_enumerationStart->m_statusModule->getPrevStatusKind(0);
        switch (prev) {
        case 0xb3:
        case 0xb4:
        case 0xb5:
        case 0xb7:
        case 0xb8:
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xbc:
            break;
        default: {
            a->m_enumerationStart->m_workManageModule->setInt(
                a->m_enumerationStart->m_areaModule
                    ->getEnviromentElementChecker()->getWaterAreaId(),
                0x20000002);

            int n = a->m_enumerationStart->m_workManageModule->getInt(0x10000014);
            if (n == 0) {
                float f = soValueAccesser::getConstantFloat(a, 0xd1e, 0);
                a->m_enumerationStart->m_workManageModule->setInt(
                    n + (int)(f * a->m_enumerationStart->m_damageModule->getDamage(0)),
                    0x10000014);
            }

            a->m_enumerationStart->m_areaModule->setAreaShapeType(
                3, (soAreaInstance::ShapeType)2);
            break;
        }
        }

        if (a->m_enumerationStart->m_situationModule->getPrevKind() == 0) {
            a->m_enumerationStart->m_workManageModule->setInt(
                lbl_27_data_30820, 0x10000027);
        }
        break;
    }

    case 0xb3: {
        a->m_enumerationStart->m_workManageModule->setInt(
            a->m_enumerationStart->m_areaModule
                ->getEnviromentElementChecker()->getWaterAreaId(),
            0x20000002);

        int n = a->m_enumerationStart->m_workManageModule->getInt(0x10000014);
        if (n == 0) {
            float f = soValueAccesser::getConstantFloat(a, 0xd1e, 0);
            a->m_enumerationStart->m_workManageModule->setInt(
                n + (int)(f * a->m_enumerationStart->m_damageModule->getDamage(0)),
                0x10000014);
        }

        int key = a->m_enumerationStart->m_workManageModule->getInt(0x20000002);
        if (!lbl_27_bss_5780) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
            if (p) {
                p = fn_27_22A914(p);
            }
            lbl_27_bss_5780 = p;
        }

        float pos[2];
        Out out;
        if ((unsigned int)(fn_27_22B3B8(lbl_27_bss_5780, key, &out) == 1) == 1 &&
            fn_27_196174(a, &out, (Vec2f*)pos) == 1) {
            setPosition(a, pos, c);
        }

        a->m_enumerationStart->m_areaModule->setAreaShapeType(
            3, (soAreaInstance::ShapeType)2);

        int prev = a->m_enumerationStart->m_statusModule->getPrevStatusKind(0);
        switch (prev) {
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
            a->m_enumerationStart->m_workManageModule->onFlag(0x22000010);
            break;
        default:
            a->m_enumerationStart->m_workManageModule->offFlag(0x22000010);
            break;
        }
        break;
    }

    case 0xb4:
        a->m_enumerationStart->m_motionModule->get2ndKind();
        break;

    case 0xbb:
        if (c[1] == a->m_enumerationStart->m_postureModule->getLr()) {
            Vec3f rot = a->m_enumerationStart->m_postureModule->getRot(0);
            rot.m_y = c[2];
            a->m_enumerationStart->m_postureModule->setRot(&rot, 0);
        }
        break;

    case 0xbc: {
        doEffect(a, c);
        break;
    }
    }
}
