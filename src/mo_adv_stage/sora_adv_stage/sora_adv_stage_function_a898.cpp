#pragma force_active on
#include <st/stage.h>
#include <st/st_data_container.h>
#include <st/st_trigger.h>
#include <gf/gf_archive.h>
#include <sr/sr_common.h>

struct Entry {
    unsigned char kind0;
    unsigned char kind1;
};

struct AdventureStage : Stage {
    gfArchive* resource;
};

extern "C" {
void* fn_40_FAC4(void* self, void* data, Entry* entry, signed char arg3);
void fn_27_233F58(void* a, void* b);
void fn_27_233FCC(void* a, void* b);

void fn_40_A898(AdventureStage* stage, u32 type, stDataMultiContainer* multi) {
    stTrigger* trigger;
    void* obj;
    void* obj2;
    stDataContainer* container;
    u32 index = 0;
    u32 i;
    Entry* entry;

    while ((container = multi->searchContainer(type, index++)) != 0) {
        for (i = 0; i < container->m_filedata->m_numFiles; ++i) {
            entry = (Entry*)container->getData(i);
            trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x17, (stTriggerData*)((char*)entry + 0x18));
            obj = operator new(0x54, Heaps::StageInstance);
            if (obj != 0) {
                obj = fn_40_FAC4(obj, stage->resource->getData(Data_Type_Scene, entry->kind0, 0xFFFE), entry, 1);
            }
            fn_27_233F58(trigger, obj);
            obj2 = operator new(0x54, Heaps::StageInstance);
            if (obj2 != 0) {
                obj2 = fn_40_FAC4(obj2, stage->resource->getData(Data_Type_Scene, entry->kind1, 0xFFFE), entry, 0);
            }
            fn_27_233FCC(trigger, obj2);
        }
    }
}
}
