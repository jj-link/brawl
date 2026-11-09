#pragma force_active on
#include <types.h>

extern "C" {
void exit__6gfTaskFv(void* t);
void* fn_1_7058(void* a, const void* b);
void* getInstance__14gfSceneManagerFv();
void playSE__9sndSystemF5SndIDiiii(void* s, int, int, int, int, int);
extern void* g_sndSystem;
}

struct TaskObj {
    char pad0[0x100];
    u8 flag100;
    char pad1[0x3];
    s32 status104;
};

struct Holder {
    char pad0[0x298];
    TaskObj* task298;
};

extern "C" s32 fn_2_EDE0(char* self) {
    Holder* h = (Holder*)self;
    TaskObj* task = h->task298;
    if (task->status104 == 3) {
        u8 b = task->flag100;
        exit__6gfTaskFv(task);
        h->task298 = NULL;
        if (b) {
            void* obj = fn_1_7058(*(void**)(self + 0x40), self + 0x44);
            void* mgr = getInstance__14gfSceneManagerFv();
            *(s32*)((char*)mgr + 0x284) = 0;
            *(s32*)((char*)mgr + 0x288) = 2;
        }
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 6, -1, 0, 0, -1);
        return 3;
    }
    return *(s32*)(self + 0x238);
}