#include <so/event/so_event_system.h>
#pragma force_active on
class Item {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void cleanup(); virtual void v6(); virtual s16 getEventId();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void flag(s32); virtual u32 check();
};
class Array {
public:
 virtual void v0(); virtual void* at(s32); virtual void v2(); virtual s32 size(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void erase(s32);
};
struct Entry { void* field0; s16 m4; s16 m6; s16 m8; };
struct This { char pad[0x2c]; Array* m_2C; char pad1[4]; Array* m_34; };
extern "C" void fn_27_97210(This* self) {
    s32 j;
    Item* item2;
    s16 id;
    s32 i;
    Item* item;
    for (i = 0; i < self->m_2C->size(); ++i) {
        if (*(void**)self->m_2C->at(i) != 0) {
            item = (Item*)*(void**)self->m_2C->at(i);
            if (item->check() == 1) {
                item2 = (Item*)*(void**)self->m_2C->at(i);
                s32 count = self->m_34->size();
                for (j = 0; j < count; ++j) {
                    s16 eventId = item2->getEventId();
                    Entry* entry = (Entry*)self->m_34->at(j);
                    if (eventId != -1) {
                        id = entry->m4;
                        if (eventId == id) {
                            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1) {
                                soEventSystem::getInstance()->getManager(entry->m4)->eraseObserver(entry->m6, entry->m8);
                            }
                            entry->m8 = -1;
                            entry->m4 = -1;
                        }
                    }
                }
                self->m_2C->erase(i);
                item2->flag(1);
                item->cleanup();
            }
        }
    }
}