#include <gf/gf_file_io_handle.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_task.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_31_3650(void*);
extern "C" int fn_800B61C0(MuObject*);
extern "C" int fn_800B6310(MuObject*);
extern "C" void fn_800B8EDC(void*, MuObject*);
extern "C" void fn_800B8A0C(void*, int);
extern char lbl_31_data_340[];

struct Param {
    union { bool b; unsigned int i; } first;
    int second;
};
struct Task {
    char pad[0x40];
    gfFileIOHandle files[3];
    void* a;
    void* b;
    char names[0xC84];
    int index;
    gfTask* task;
    MuObject* object;
    void* resource;
    unsigned int state;
    int counter;
};

extern "C" void fn_31_3294(Task* self) {
    const char* data = lbl_31_data_340;
    gfPadStatus pad;
    Param tmp, p, copy;
    if (g_GameGlobal->m_advData) {
        p.first.i = g_GameGlobal->m_advData->m_record.unk4928;
        p.second = g_GameGlobal->m_advData->m_record.unk492C;
    } else {
        tmp.first.b = false;
        tmp.second = -1;
        p = tmp;
    }
    copy = p;
    g_gfPadSystem->getSysPadStatus(copy.second, &pad);
    switch (self->state) {
    case 0:
        self->files[0].readRequest(data + 0x84c, (Heaps::HeapType)0x2b, 0, 0);
        self->files[1].readRequest(self->names + self->index * 64, (Heaps::HeapType)0x2b, 0, 0);
        self->files[2].readRequest(data + 0x868, (Heaps::HeapType)0x2b, 0, 0);
        self->state = 1;
        break;
    case 1:
        {
            int waiting;
            waiting = !self->files[0].isReady() ? 1 : (!self->files[1].isReady() ? 1 : !self->files[2].isReady());
            if (!waiting) self->state = 2;
        }
        break;
    case 2:
        fn_31_3650(self);
        self->state = 3;
        break;
    case 3:
        g_sndSystem->playSE((SndID)0xd7, -1, 0, 0, -1);
        self->object->changeNodeAnimNIf(data + 0x888);
        self->object->changeClrAnimNIf(data + 0x888);
        self->state = 4;
        break;
    case 4:
        if ((!fn_800B61C0(self->object) ? 0u : (unsigned int)(fn_800B6310(self->object) != 0)) == 1u)
            self->state = 5;
        break;
    case 5:
        self->object->changeNodeAnimNIf(data + 0x8a0);
        self->object->changeClrAnimNIf(data + 0x8a0);
        self->state = 6;
        break;
    case 6:
        if (pad.m_buttonsPressedThisFrame.bits & 0x100) {
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            self->state = 7;
        }
        break;
    case 7:
        self->object->changeNodeAnimNIf(data + 0x8b8);
        self->object->changeClrAnimNIf(data + 0x8b8);
        self->state = 8;
        break;
    case 8:
        if ((!fn_800B61C0(self->object) ? 0u : (unsigned int)(fn_800B6310(self->object) != 0)) == 1u)
            self->state = 9;
        break;
    case 9:
        fn_800B8EDC(self->resource, self->object);
        fn_800B8A0C(self->resource, 1);
        self->resource = 0;
        self->task->exit();
        self->task = 0;
        delete self->object;
        self->object = 0;
        self->files[0].release();
        self->files[1].release();
        gfHeapManager::free(self->files[2].getBuffer());
        self->files[2].release();
        operator delete(self->a);
        operator delete(self->b);
        ((gfTask*)self)->exit();
        self->state++;
        break;
    }
    self->counter++;
}