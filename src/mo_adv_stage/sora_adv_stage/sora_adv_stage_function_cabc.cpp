#include <st/st_trigger.h>
#include <st/st_data_container.h>
#pragma force_active on

extern "C" void* fn_27_2372C8(void*, void*);

extern "C" void fn_40_CABC(void* self, u32 kind, stDataMultiContainer* multi) {
    stTrigger* trigger;
    stDataContainer* container;
    u32 index = 0;
    u32 i;
    char* entry;
    void* obj;
    while ((container = multi->searchContainer(kind, index++)) != 0) {
        for (i = 0; i < container->m_filedata->m_numFiles; i++) {
            entry = (char*)container->getData(i);
            trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0, (stTriggerData*)(entry + 4));
            obj = operator new(0x14, (Heaps::HeapType)0xf);
            if (obj) {
                obj = fn_27_2372C8(obj, entry);
            }
            trigger->setValidCallback((gfCallBack*)obj);
        }
    }
}
