#pragma force_active on
#include <gf/gf_scene.h>

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_3_272C(void*, int);

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void fn_1_8AE0();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
};

struct Scene {
    char pad[8];
    gfTask* task;
};

extern "C" void fn_1_91F4(Scene* self) {
    gfTask* task;
    switch (gfSceneManager::getInstance()->m_memoryLayout) {
    case 0:
        task = (gfTask*)__nw__FUlQ25Heaps8HeapType(0xB20, 0x2A);
        if (task) {
            task = (gfTask*)fn_3_272C(task, 0);
        }
        task->init();
        self->task = task;
        break;
    case 1:
        task = (gfTask*)__nw__FUlQ25Heaps8HeapType(0xB20, 0x2A);
        if (task) {
            task = (gfTask*)fn_3_272C(task, 1);
        }
        task->init();
        self->task = task;
        break;
    case 2:
        task = (gfTask*)__nw__FUlQ25Heaps8HeapType(0xB20, 0x2A);
        if (task) {
            task = (gfTask*)fn_3_272C(task, 2);
        }
        task->init();
        self->task = task;
        break;
    case 3:
        task = (gfTask*)__nw__FUlQ25Heaps8HeapType(0xB20, 0x2A);
        if (task) {
            task = (gfTask*)fn_3_272C(task, 3);
        }
        task->init();
        self->task = task;
        break;
    }
}
