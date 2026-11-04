#include <gf/gf_module.h>
#include <gf/gf_memory_pool.h>
#pragma force_active on

struct ModuleEntry {
    const char* name;
    int unused;
    unsigned char flag;
    unsigned char state;
    char pad[2];
};
struct SceneManager {
    char pad[0x290];
    ModuleEntry entries[11];
    int state;
    int index;
};
extern gfModuleManager* lbl_805A0038;

extern "C" int loadModule__14gfSceneManagerFv(SceneManager* self) {
    int result = 0;
    switch (self->state) {
    case 0:
        for (int i = 0; i < 11; i++) {
            if (self->entries[i].name && self->entries[i].state == 1) {
                self->index = i;
                if (self->entries[i].flag) {
                    lbl_805A0038->setTempolaryLoadHeap((HeapType)6);
                    gfModuleManager::LoadRequestResult req;
                    gfModuleManager::loadModuleRequest(&req, lbl_805A0038, self->entries[self->index].name, (HeapType)0x32, true, false);
                } else {
                    if (g_HeapInfos[0x2a].m_name)
                        lbl_805A0038->setTempolaryLoadHeap((HeapType)0x2a);
                    else
                        lbl_805A0038->setTempolaryLoadHeap((HeapType)0x28);
                    gfModuleManager::LoadRequestResult req;
                    gfModuleManager::loadModuleRequest(&req, lbl_805A0038, self->entries[self->index].name, (HeapType)0x34, true, false);
                }
                self->state = 1;
                result = 1;
                break;
            }
        }
        break;
    case 1:
        if (lbl_805A0038->isLoaded(self->entries[self->index].name) == true) {
            self->entries[self->index].state = 2;
            self->state = 0;
        }
        result = 1;
        break;
    }
    return result;
}