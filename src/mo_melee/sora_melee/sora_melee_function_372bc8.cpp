#include <so/so_module_accesser.h>
#include <types.h>

#pragma force_active on
#pragma fp_contract off

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern const float lbl_27_rodata_7BC0;
extern const float lbl_27_rodata_7BD0;
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
int fn_27_1922CC(void*, unsigned long);
float fn_27_192278(void*, unsigned long);
}

extern "C" void fn_27_372BC8(void*, soModuleAccesser* obj) {
    int status = obj->m_enumerationStart->m_statusModule->getStatusKind();

    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, obj, 1)) {
    case 0x117: {
        if (obj->m_enumerationStart->m_workManageModule->getInt(0x20000003) == 0) {
            int r30 = obj->m_enumerationStart->m_workManageModule->getInt(0x10000040);
            if (r30 >= fn_27_1922CC(obj, 0x5dc0)) {
                int id;
                if (obj->m_enumerationStart->m_workManageModule->isFlag(0x22000013) == 1) {
                    int nodeId = obj->m_enumerationStart->m_modelModule->getRealNodeId(0x19c);
                    Vec3f pos;
                    Vec3f rot;
                    rot.m_x = lbl_27_rodata_7BC0;
                    rot.m_y = lbl_27_rodata_7BC0;
                    rot.m_z = lbl_27_rodata_7BC0;
                    pos.m_x = lbl_27_rodata_7BC0;
                    pos.m_y = lbl_27_rodata_7BC0;
                    pos.m_z = lbl_27_rodata_7BC0;
                    id = obj->m_enumerationStart->m_effectModule->reqFollow((EfID)0x1f000c, nodeId, &pos, &rot, lbl_27_rodata_7BD0, 0, 0, 0, -1);
                } else {
                    Vec3f pos;
                    Vec3f rot;
                    rot.m_x = lbl_27_rodata_7BC0;
                    rot.m_y = lbl_27_rodata_7BC0;
                    rot.m_z = lbl_27_rodata_7BC0;
                    pos.m_x = lbl_27_rodata_7BC0;
                    pos.m_y = lbl_27_rodata_7BC0;
                    pos.m_z = lbl_27_rodata_7BC0;
                    id = obj->m_enumerationStart->m_effectModule->reqFollow((EfID)0x1f000c, 8, &pos, &rot, lbl_27_rodata_7BD0, 0, 0, 0, -1);
                }
                obj->m_enumerationStart->m_workManageModule->setInt(id, 0x20000003);
            }
        }
        break;
    }
    case 0x118: {
        float f31;
        float f30;
        if (obj->m_enumerationStart->m_workManageModule->isFlag(0x22000011) == 1) {
            if (obj->m_enumerationStart->m_workManageModule->isFlag(0x22000012) == 0) {
                float v;
                if (obj->m_enumerationStart->m_workManageModule->isFlag(0x22000013) == 1) {
                    int nodeId = obj->m_enumerationStart->m_modelModule->getRealNodeId(0x19c);
                    Vec3f r = obj->m_enumerationStart->m_motionModule->getNodeRotate(nodeId);
                    v = r.m_x;
                } else {
                    Vec3f r = obj->m_enumerationStart->m_motionModule->getNodeRotate(7);
                    v = r.m_x;
                }
                obj->m_enumerationStart->m_workManageModule->setFloat(v, 0x21000005);
                obj->m_enumerationStart->m_workManageModule->onFlag(0x22000012);
            }
            f30 = obj->m_enumerationStart->m_controllerModule->getStickY();
            f31 = fn_27_192278(obj, 0xFA0);
            if (f30 >= lbl_27_rodata_7BC0) {
                float s1 = fn_27_192278(obj, 0xFA1);
                f30 = f31 + f30 * (s1 - f31);
            } else {
                float s2 = -fn_27_192278(obj, 0xFA2);
                f30 = f31 + (-f30) * (s2 - f31);
            }
            f31 = obj->m_enumerationStart->m_workManageModule->getFloat(0x21000004);
            float limit = fn_27_192278(obj, 0xFA3);
            float d = f30 - f31;
            if (d > limit) {
                d = limit;
            } else if (d < -limit) {
                d = -limit;
            }
            f30 = f31 + d;
            obj->m_enumerationStart->m_workManageModule->setFloat(f30, 0x21000004);
            if (obj->m_enumerationStart->m_workManageModule->isFlag(0x22000013) == 0) {
                float diff = obj->m_enumerationStart->m_workManageModule->getFloat(0x21000005) - f30;
                obj->m_enumerationStart->m_modelModule->setNodeRotateX(7, diff);
            }
        }
        break;
    }
    }
}
