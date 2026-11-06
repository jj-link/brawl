#include <ty/ty_fig_listmng.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

struct Entry {
    u16 refs;
    u16 type;
    int state;
    u32 id;
    tyFigListData* data;
    u32 unk10;
    gfFileIOHandle handle;
    char rest[0x88];
};
struct Manager {
    tyFigListDataManager* list;
    int count;
    Entry* entries;
    int current;
};

extern "C" void fn_801063CC(Entry** out, Manager* manager, u32 id) {
    tyFigListData* data = manager->list->getFigDataId(id);
    if (!data) {
        *out = 0;
        return;
    }
    for (int i = 0; i < manager->count; i++) {
        if (manager->entries[i].data == data) {
            manager->entries[i].refs++;
            *out = &manager->entries[i];
            return;
        }
    }
    int start = manager->current + 1;
    for (int i = 0; i < manager->count + 1; i++) {
        int index = (start + i) % manager->count;
        manager->current = index;
        Entry* entry = &manager->entries[index];
        if (entry->refs == 0) {
            entry->refs++;
            entry->id = id;
            entry->data = data;
            entry->type = 3;
            if (entry->state == 0) {
                if (entry->handle.m_request && !entry->handle.isReady()) {
                    entry->state = 2;
                    entry->handle.cancelRequest();
                } else {
                    entry->state = 1;
                }
            }
            *out = entry;
            return;
        }
    }
    *out = 0;
}