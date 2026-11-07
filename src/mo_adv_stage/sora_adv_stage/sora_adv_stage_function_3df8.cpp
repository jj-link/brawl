#include <st/st_trigger.h>
#include <st/st_data_container.h>
#pragma force_active on

extern "C" void fn_27_2341C4(stTrigger*, stTriggerData*);

extern "C" void fn_40_3DF8(void* self, u32 kind, stDataMultiContainer* multi) {
    stDataContainer* container;
    u32 n = 0;
    while ((container = multi->searchContainer(kind, n++)) != 0) {
        for (u32 i = 0; i < container->m_filedata->m_numFiles; i++) {
            stTriggerData* data = (stTriggerData*)container->getData(i);
            stTrigger* trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)5, (stTriggerData*)((u8*)data + 0x14));
            fn_27_2341C4(trigger, data);
        }
    }
}
