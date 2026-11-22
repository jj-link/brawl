#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

extern "C" {
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void fn_801B92BC(void* p, u32 n);
void* fn_801BB188(void);
void* fn_801BB610(void* heap, u32 flags, void (*cb)(void*, s32, void*), void* arg);
void fn_801BB8E0(void* heap, void* item);
void fn_801D049C(void* p, u32 a, u32 b, u32 c, u32 d);
void* fn_801D2AD0(void);
void fn_801D1CBC(void* a, s32 b, void* c);
}

struct Entry { s32 rows, cols; char pad[0x10]; s32 priority; };
typedef nw4r::ut::LinkList<Entry, 0x88> EntryList;

extern "C" s32 fn_801D0B68(s32 intr, s32 a1, s32 a2, void* self, s32 a3, s32 a4) {
    s32 rows;
    s32 cols;
    void** slot;
    u32 flags;
    u32 flags2;
    s32 total;
    s32 n;
    s32 remaining;
    s32 a5 = a4;
    a4 = a3;
    a3 = (s32)self;
    self = (void*)intr;
    void* r;
    u8* node;
    u8* list;
    void** src;
    void** p;
    u8* row;
    u8* dst;
    s32 i;
    s32 j;
    void* items[8];

    if (a1 > 2) {
        rows = 2;
    } else {
        rows = 1;
        if (a1 >= 1) {
            rows = a1;
        }
    }
    if (a2 > 4) {
        cols = 4;
    } else {
        cols = 1;
        if (a2 >= 1) {
            cols = a2;
        }
    }
    {
        intr = OSDisableInterrupts();
        flags = 0x10;
        if (a3 == 0xFF) {
            flags = 0x1F;
        }
        total = rows * cols;
        slot = items;
        n = 0;
        while (n < total) {
            r = fn_801BB610(fn_801BB188(), flags, fn_801D1CBC, self);
            if (r == 0) {
                remaining = total - n;
                nw4r::ut::LinkListNode* head = (nw4r::ut::LinkListNode*)((u8*)fn_801D2AD0() + 8);
                EntryList::Iterator end = EntryList::GetIteratorFromPointer(head);
                for (EntryList::Iterator it = EntryList::GetIteratorFromPointer(head->GetNext()); it != end; ++it) {
                    if (a3 < it->priority) {
                        break;
                    }
                    remaining -= it->rows * it->cols;
                    if (remaining <= 0) {
                        break;
                    }
                }
                if (remaining > 0) {
                    a3 = (s32)items;
                    for (self = 0; (s32)self < n; self = (void*)((s32)self + 1)) {
                        fn_801BB8E0(fn_801BB188(), *(void**)a3);
                        a3 += 4;
                    }
                    OSRestoreInterrupts(intr);
                    return 0;
                }
                flags2 = 0x11;
                if (flags == 0x1F) {
                    flags2 = 0x1F;
                }
                r = fn_801BB610(fn_801BB188(), flags2, fn_801D1CBC, self);
            }
            if (r == 0) {
                a3 = (s32)items;
                for (self = 0; (s32)self < n; self = (void*)((s32)self + 1)) {
                    fn_801BB8E0(fn_801BB188(), *(void**)a3);
                    a3 += 4;
                }
                OSRestoreInterrupts(intr);
                return 0;
            }
            *slot = r;
            slot++;
            n++;
        }

        row = (u8*)self;
        src = items;
        for (i = 0; i < rows; i++) {
            dst = row;
            for (j = 0; j < cols; j++) {
                fn_801B92BC(*src, flags);
                *(void**)(dst + 0xC) = *src;
                src++;
                dst += 4;
            }
            row += 0x10;
        }
        fn_801D049C(self, rows, cols, a4, a5);
        *(u8*)((u8*)self + 0xAC) = 1;
        OSRestoreInterrupts(intr);
        return 1;
    }
}