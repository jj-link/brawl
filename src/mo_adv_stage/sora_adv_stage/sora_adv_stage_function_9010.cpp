#include <st/st_trigger.h>
#include <st/st_data_container.h>
#pragma force_active on

struct Src { int x; int y; };

extern "C" void* fn_40_F95C(void* self, const Src* src, int x);
extern "C" void fn_27_233F58(void*, void*);

extern "C" void fn_40_9010(void* self, u32 kind, stDataMultiContainer* multi) {
    stTrigger* trigger;
    stDataContainer* container;
    u32 index = 0;
    u32 i;
    char* entry;
    void* obj;
    while ((container = multi->searchContainer(kind, index++)) != 0) {
        for (i = 0; i < container->m_filedata->m_numFiles; i++) {
            entry = (char*)container->getData(i);
            trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0, (stTriggerData*)(entry + 0x10));
            obj = operator new(0x18, (Heaps::HeapType)0xf);
            if (obj) {
                Src src = *(Src*)((char*)self + 0x588);
                obj = fn_40_F95C(obj, &src, (int)entry);
            }
            fn_27_233F58(trigger, obj);
        }
    }
}
