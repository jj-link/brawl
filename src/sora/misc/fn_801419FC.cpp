#include <types.h>
#pragma force_active on

struct NetEntry {
    u8 flagA;
    u8 flagB;
    u8 pad[0x12];
    u32 tick;
};

struct NetElem {
    u32 state;
    NetElem* next;
    NetElem* prev;
    u8 unkC;
    u8 unkD;
    u16 seq;
    u8 unk10[4];
    NetEntry entries[4];
    u8* buf;
};

struct NetCtx {
    u8 pad0[0x14];
    u8 count;
    u8 pad15[0x50 - 0x15];
    u32 maxSize;
    u32 stride;
    u8 pad58[0x142 - 0x58];
    u16 seq;
    u8 pad144[0x164 - 0x144];
    u32 memSize;
    u8 pad168[0x1BC - 0x168];
    u8 flag1BC;
    u8 pad1BD[0x1D0 - 0x1BD];
    s32 delay;
    u8 pad1D4[0x450 - 0x1D4];
    NetElem* listHead;
    NetElem* listTail;
    NetElem* freeHead;
};

extern "C" {
u32 OSGetTick(void);
void fn_80141D28(NetCtx* self, u16 seq, u8* buf, NetEntry* entry);
void netReport__FPCce(const char* fmt, ...);
void* memcpy(void*, const void*, unsigned long);
void* memset(void*, int, unsigned long);
}

extern char lbl_8045E3BC[];
extern char lbl_8045E3D8[];
extern u8 lbl_8059E742;
extern u8 lbl_805A0418[8];
extern void (*lbl_805A0398)(s32*, u32*, u16);

extern "C" void fn_801419FC(void* arg0) {
    NetElem* elem;
    NetCtx* self;
    NetEntry* entry;
    s32 spC;
    u32 sp8;
    u16 seq;
    u8 i;
    u8* p;

    self = (NetCtx*)arg0;
    if (self->delay > 0) {
        self->delay--;
        return;
    }
    elem = self->freeHead;
    if (elem == NULL) {
        elem = NULL;
    } else {
        self->freeHead = elem->next;
        elem->next = NULL;
        elem->prev = NULL;
        self->count++;
        if (self->listHead != NULL) {
            self->listHead->prev = elem;
            elem->next = self->listHead;
        }
        self->listHead = elem;
        if (self->listTail == NULL) {
            self->listTail = elem;
        }
    }
    if (elem != NULL) {
        memset(elem->buf + self->stride * lbl_805A0418[0], 0, self->memSize);
        if (self->flag1BC == 0 && lbl_805A0398 != NULL) {
            lbl_805A0398(&spC, &sp8, self->seq);
            if (spC == 0) {
                netReport__FPCce(lbl_8045E3BC, self->seq);
                if (elem->prev != NULL) {
                    elem->prev->next = elem->next;
                }
                if (elem->next != NULL) {
                    elem->next->prev = elem->prev;
                }
                if (self->listTail == elem) {
                    self->listTail = elem->prev;
                }
                if (self->listHead == elem) {
                    self->listHead = elem->next;
                }
                elem->state = 0;
                elem->next = self->freeHead;
                elem->prev = NULL;
                self->freeHead = elem;
                if (self->count != 0) {
                    self->count--;
                }
                return;
            }
            if (sp8 > self->maxSize) {
                netReport__FPCce(lbl_8045E3D8, sp8, self->maxSize);
            }
            memcpy(elem->buf + self->stride * lbl_805A0418[lbl_8059E742 * 2], (void*)spC, sp8);
        }
        entry = &elem->entries[lbl_8059E742];
        entry->tick = OSGetTick();
        seq = self->seq;
        elem->seq = seq;
        self->seq = seq + 1;
        elem->state = 2;
        elem->unkD = 0;
        for (i = 0; i < 4; i++) {
            p = (u8*)elem + i * 0x18;
            p[0x14] = 0;
            p[0x15] = 0;
            if (i == lbl_8059E742) {
                elem->entries[lbl_8059E742].flagA = 1;
                elem->entries[lbl_8059E742].flagB = 1;
            }
        }
        fn_80141D28(self, elem->seq, elem->unk10, entry);
    }
}
