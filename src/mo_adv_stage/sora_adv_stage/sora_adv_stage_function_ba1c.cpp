#include <types.h>
#include <st/st_data_container.h>
#include <st/st_trigger.h>
#pragma force_active on

extern const float lbl_40_rodata_2C[];
extern const float lbl_40_rodata_78;
extern "C" void fn_27_2336E8(stTrigger*, grGimmickWindData2nd*);

extern "C" void fn_40_BA1C(void* self, u32 kind, stDataMultiContainer* multi) {
    stDataContainer* container;
    u32 n = 0;
    float range;
    float zero;
    zero = lbl_40_rodata_2C[0];
    range = lbl_40_rodata_78;
    while ((container = multi->searchContainer(kind, n++)) != 0) {
        for (u32 i = 0; i < container->m_filedata->m_numFiles; i++) {
            grGimmickWindData2nd* data = (grGimmickWindData2nd*)container->getData(i);
            stTrigger* trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)13, -1);
            if (trigger) {
                data->m_pos = Vec3f(zero, zero, zero);
                *(float*)((char*)data + 0x18) = zero;
                *(float*)((char*)data + 0x1c) = zero;
                *(float*)((char*)data + 0x20) = range;
                *(float*)((char*)data + 0x24) = range;
                fn_27_2336E8(trigger, data);
            }
        }
    }
}
