#pragma force_active on
#include <st/st_trigger.h>
#include <st/st_data_container.h>

extern "C" void fn_27_234338(stTrigger*, stTriggerData*);

extern "C" void fn_40_C910(void* self, u32 kind, stDataMultiContainer* multi) {
    stDataContainer* container;
    u32 n = 0;
    while ((container = multi->searchContainer(kind, n++)) != 0) {
        for (u32 i = 0; i < container->m_filedata->m_numFiles; i++) {
            stDataContainerData* data = container->getData(i);
            stTrigger* trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)6, (stTriggerData*)((u8*)data + 0x14));
            fn_27_234338(trigger, (stTriggerData*)data);
        }
    }
}
