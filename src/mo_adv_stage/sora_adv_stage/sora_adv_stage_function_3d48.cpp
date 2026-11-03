#pragma force_active on
#include <st/st_data_container.h>
#include <st/st_trigger.h>

extern "C" {
void fn_27_234574(void* trigger, void* data);
}

extern "C" void fn_40_3D48(void* self, u32 kind, stDataMultiContainer* multi) {
    stDataContainer* container;
    u32 i = 0;

    while ((container = multi->searchContainer(kind, i++)) != 0) {
        for (u32 j = 0; j < container->m_filedata->m_numFiles; j++) {
            stDataContainerData* data = container->getData(j);
            fn_27_234574(g_stTriggerMng->createTrigger(Gimmick::AreaKind(7), (stTriggerData*)((u8*)data + 0x14)), data);
        }
    }
}
