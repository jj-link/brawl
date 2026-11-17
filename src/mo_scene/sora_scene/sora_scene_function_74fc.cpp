#pragma force_active on
#include <types.h>

class gfTask_base {
public:
    char pad[0x3C];
};

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

extern "C" {
void* getInstance__14gfSceneManagerFv();
void* getInstance__9itManagerFv();
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* __ct__20tyFigListDataManagerFb(void* self, int arg);
int fn_80052DB0();
gfTask* fn_800BA7C0(void* self, int a, void* b, int c);
void fn_800BD510(void* self, int idx, int flag);
int fn_80055398(int idx);
void* fn_8004E5AC(int g);
extern int g_GameGlobal;
}

extern "C" void fn_1_74FC(unsigned char* self) {
    s32 r;
    gfTask* task;
    void* list;
    *(void**)(self + 0x10) = 0;
    *(s32*)(self + 0x14) = *(s32*)((unsigned char*)getInstance__14gfSceneManagerFv() + 0x280);
    void* mgr = *(void**)((unsigned char*)getInstance__9itManagerFv() + 0x14B8);
    if (mgr != 0) {
        list = *(void**)((unsigned char*)mgr + 4);
    } else {
        void* p = __nw__FUlQ25Heaps8HeapType(0x1468, 0x2A);
        if (p != 0) {
            p = __ct__20tyFigListDataManagerFb(p, 1);
        }
        list = p;
        *(void**)(self + 0x10) = p;
    }
    if (*(s32*)(self + 0x14) != 1) {
        r = fn_80052DB0();
        task = (gfTask*)__nw__FUlQ25Heaps8HeapType(0x1308, 0x2A);
        if (task != 0) {
            task = fn_800BA7C0(task, 0, list, r);
        }
        task->init();
        *(gfTask**)(self + 8) = task;
    } else {
        r = fn_80052DB0();
        task = (gfTask*)__nw__FUlQ25Heaps8HeapType(0x1308, 0x2A);
        if (task != 0) {
            task = fn_800BA7C0(task, 1, list, r);
        }
        task->init();
        *(gfTask**)(self + 8) = task;
    }
    if (*(s32*)(self + 0x14) == 1) {
        for (s32 i = 0; i < 0x80; i++) {
            if (fn_80055398(i) == 0) {
                u32* words = (u32*)fn_8004E5AC(g_GameGlobal);
                if ((u32)((words[i / 32] & (1u << (i % 32))) != 0) == 1) {
                    fn_800BD510(*(void**)(self + 8), i, 1);
                }
            }
        }
    }
    self[0xC] = 0;
}
