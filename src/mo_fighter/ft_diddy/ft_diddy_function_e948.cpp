#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" {
void* getInstance__9itManagerFv();
void* getItemFromInstanceId__9itManagerFi(void*, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
extern const float lbl_115_rodata_50;
extern const float lbl_115_rodata_54;
void fn_27_28E108(void*, float, float*, float);
}

extern "C" void fn_115_E948(void*, soModuleAccesser* a) {
    if (a->m_enumerationStart->m_workManageModule->isFlag(0x22000012)) {
        if (a->m_enumerationStart->m_workManageModule->isFlag(0x22000014)) {
            int instanceId = a->m_enumerationStart->m_workManageModule->getInt(0x20000000);
            void* item = getItemFromInstanceId__9itManagerFi(getInstance__9itManagerFv(), instanceId);
            float vx;
            float angle = lbl_115_rodata_50 * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xFB9, 0);
            float length = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xFBA, 0);
            float lr = a->m_enumerationStart->m_postureModule->getLr();
            if (a->m_enumerationStart->m_workManageModule->isFlag(0x22000011)) {
                length *= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xFBB, 0);
            }
            float height = a->m_enumerationStart->m_groundModule->getZ();
            vx = length * (float)sin(angle);
            float vy = lr * (length * (float)cos(angle));
            float v[3];
            v[0] = vy;
            v[1] = vx;
            v[2] = height;
            if (item) {
                fn_27_28E108(item, lr, &v[0], lbl_115_rodata_54);
            }
            a->m_enumerationStart->m_workManageModule->offFlag(0x22000014);
        }
        a->m_enumerationStart->m_workManageModule->offFlag(0x22000012);
    }
}