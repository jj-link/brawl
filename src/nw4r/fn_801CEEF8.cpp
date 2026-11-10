#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern "C" {
extern char lbl_80466C78[];
void* fn_801C0A0C(void*);
void* fn_801CFA14();
void fn_801CFB8C(void*, void*, int);
}

struct List : nw4r::ut::detail::LinkListImpl {
    using nw4r::ut::detail::LinkListImpl::Insert;
};
struct Task {
    void* vtable;
    u32 a, b;
    u8 c;
    void* owner;
    u32 d, e, f, g;
    s32 h;
    u8 i;
    u32 node[2];
    Task() : a(0), b(0), c(0) {
        vtable = lbl_80466C78;
        owner = 0; d = 0; e = 0; f = 0; g = 0; h = -1; i = 0;
        node[0] = 0;
        node[1] = 0;
    }
};
struct Object {
    char pad0[0x80];
    u8 mode, loop, channels;
    char pad83[5];
    u16 header;
    char pad8a[10];
    s32 offset, count, block;
    char pada0[12];
    s32 last;
    char padb0[10];
    u8 flag;
    char padbb[11];
    u8 done;
    char padc7[21];
    s32 base, limit, index, frame;
    char padec[12];
    s32 start, end;
    char pad100[0x28];
    List list;
    char pool[0x688];
    s32 data;
    char pad7c0[4];
    s32 stride;
};
extern "C" void fn_801CEEF8(Object* self) {
    if (!self->done) {
        Task* task;
        s32 size;
        if (self->frame < self->count - 1)
            size = self->block;
        else
            size = self->last;
        s32 offset = self->header + self->stride * ((size + 31) & ~31);
        s32 pos = self->offset + self->frame * (self->header + self->block * self->channels);
        bool first = false;
        if (self->index == 0 && self->mode == 2)
            first = true;
        void* mem = fn_801C0A0C(self->pool);
        if (mem == 0) task = 0;
        else task = new (mem) Task;
        task->owner = self;
        task->d = self->data;
        task->e = offset;
        task->f = pos;
        task->g = size;
        task->h = self->index;
        task->i = first;
        BOOL enabled = OSDisableInterrupts();
        self->list.Insert(nw4r::ut::detail::LinkListImpl::Iterator((nw4r::ut::LinkListNode*)((char*)&self->list + 4)), (nw4r::ut::LinkListNode*)task->node);
        size = 1;
        if (self->flag) size = 2;
        fn_801CFB8C(fn_801CFA14(), task, size);
        self->frame++;
        if (self->frame > self->end) {
            if (self->loop) self->frame = self->start;
            else {
                self->done = 1;
                OSRestoreInterrupts(enabled);
                return;
            }
        }
        self->index++;
        if (self->index >= self->limit) {
            s32 end = self->end;
            s32 value = self->base;
            self->index = 0;
            s32 next = value + 1;
            if ((next - (end - self->frame + 1)) % (end - self->start + 1) == 0)
                value = next;
            self->limit = value;
        }
        OSRestoreInterrupts(enabled);
    }
}