#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern const float lbl_115_rodata_38[];
extern const char lbl_115_data_7650[];
extern const char lbl_115_data_2984[], lbl_115_data_3200[];

int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
float fn_27_192278(void*, unsigned long);
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_115_E59C(float value);
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void* getInstance__9itManagerFv();
void* fn_27_2A66B8(void*, Vec3f*, Vec3f*, float, int, unsigned int, int, int, int, int, int, int, int, int);
void fn_27_28E108(void*, float, Vec3f*, float);
void fn_27_28F96C(void*);
double sin(double);
double cos(double);
}

extern "C" void fn_115_E100(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_115_rodata_38;
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, accesser->getStatusModule().getStatusKind(), accesser, 1)) {
    case 0x118: {
        if (!accesser->getWorkManageModule().isFlag(0x22000012)) {
            accesser->getWorkManageModule().onFlag(0x22000012);
            float f31 = fn_27_192278(accesser, 0xfa1);
            f31 = fn_115_E59C(fn_27_192278(accesser, 0xfa0) - f31);
            float var30 = f31 * (accesser->getWorkManageModule().getFloat(0x21000004) / constants[2]);
            var30 = fn_27_192278(accesser, 0xfa0) - var30;
            if (var30 < constants[0]) {
                var30 = constants[0];
            }
            float var29;
            if (accesser->getWorkManageModule().isFlag(0x22000011)) {
                f31 = fn_27_192278(accesser, 0xfa3);
                f31 = fn_115_E59C(fn_27_192278(accesser, 0xfa5) - f31);
                f31 = f31 * (accesser->getWorkManageModule().getFloat(0x21000005) / constants[3]);
                var29 = fn_27_192278(accesser, 0xfa3);
                var29 = var29 + f31;
                var30 = fn_27_192278(accesser, 0xfa1);
            } else {
                f31 = fn_27_192278(accesser, 0xfa2);
                f31 = fn_115_E59C(fn_27_192278(accesser, 0xfa3) - f31);
                f31 = f31 * (accesser->getWorkManageModule().getFloat(0x21000004) / constants[2]);
                var29 = fn_27_192278(accesser, 0xfa2);
                var29 = var29 + f31;
            }
            var30 = constants[4] * var30;
            float lr = accesser->getPostureModule().getLr();
            soGroundModule& ground = accesser->getGroundModule();
            f31 = (float)sin(var30);
            var30 = (float)cos(var30);
            Vec3f velocity;
            fn_115_8EF8(&velocity, lr * (var29 * var30), var29 * f31, ground.getZ());
            Vec3f nodePos;
            Vec3f offset;
            offset.m_x = constants[0];
            offset.m_y = fn_27_192278(accesser, 0xfa8);
            offset.m_z = fn_27_192278(accesser, 0xfa7);
            int nodeId = accesser->getModelModule().getNodeId(lbl_115_data_7650);
            nodePos = accesser->getModelModule().getNodeGlobalPosition(nodeId, &offset, false, false);
            soGroundModule& ground2 = accesser->getGroundModule();
            Vec3f groundPos;
            fn_115_8EF8(&groundPos, (accesser->getGroundModule().getCenterPos(0)).m_x, (ground2.getCenterPos(0)).m_y, ground2.getZ());
            __dynamic_cast(accesser->m_stageObject, 0x3C, lbl_115_data_2984, lbl_115_data_3200, 1);
            int stageField = *reinterpret_cast<int*>(reinterpret_cast<char*>(accesser->m_stageObject) + 0x28);
            void* itMgr = getInstance__9itManagerFv();
            void* item = fn_27_2A66B8(itMgr, &groundPos, &nodePos, lr, 0x54, 0, stageField, stageField, 0, 0, 0xFFFF, 0, 0xFFFF, 0x14);
            if (item != 0) {
                accesser->getPostureModule().getScale();
                fn_27_28F96C(item);
                fn_27_28E108(item, lr, &velocity, constants[1]);
            }
        }
        break;
    }
    }
}
