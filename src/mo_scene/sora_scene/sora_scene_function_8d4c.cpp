#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
char* strcpy(char*, const char*);
}

struct TaskGroup {
    void* tasks[3];
};

struct Task {
    char pad[0x1AC];
    void* unk1AC;
};

class Scene {
public:
    char _unk[0x35C];
    TaskGroup* m_tasks;
    u32 unk360;
    char unk364[0x20];
};

extern "C" s32 fn_1_8D4C(Scene* self) {
    TaskGroup* group = self->m_tasks;
    Task* task = (Task*)group->tasks[1];
    gfSceneManager* mgr = gfSceneManager::getInstance();
    switch (mgr->unk1) {
    case 0:
        self->unk360 = *(u32*)((char*)task->unk1AC + 0x1A0);
        strcpy(self->unk364, *(char**)((char*)task->unk1AC + 0x1CE4) + 0x15D);
        break;
    case 1:
        break;
    }
    if (self->m_tasks == nullptr) {
        return 0;
    }
    exit__6gfTaskFv(self->m_tasks->tasks[0]);
    exit__6gfTaskFv(self->m_tasks->tasks[1]);
    exit__6gfTaskFv(self->m_tasks->tasks[2]);
    free__13gfHeapManagerFPv(self->m_tasks);
    self->m_tasks = nullptr;
    return 0;
}
