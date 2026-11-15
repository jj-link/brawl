#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <gf/gf_task.h>
#include <nt/nt_report.h>
#include <string.h>
#include <types.h>

extern "C" {
s32 fn_800305B0(s32);
s32 fn_80030548(s32);
void* fn_80030DEC(s32, s32);
s32 fn_80030F58(s32);
void fn_800307B4(void);
s32 fn_80351304(void*);
u32 fn_80351610(void*);
void fn_8035161C(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
s16 NETCalcCRC16(void*, s32);
s16 srSystemGetRevisionNumber__Fv(void);
}

extern s32 lbl_805A0448;
extern void* lbl_805A044C;

struct NtPacket {
    u16 magic;
    u16 crc;
    u16 rev;
    u8 pad6;
};

struct NtObj {
    NtPacket* hdr;
    u32 size;
    u8 flag;
    u8 f9;
};

static inline void adjust(unsigned int* field, unsigned int remainder) {
    if (remainder) *(long*)field += 32 - remainder;
}

static inline NtObj* getInstance() {
    int alignment = 4;
    if (lbl_805A044C == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0xC, 0x2D);
        if (p != 0) {
            unsigned int* sizeField = (unsigned int*)((char*)p + 4);
            *sizeField = 0x2804;
            adjust(sizeField, *sizeField & 31);
            *(void**)p = gfHeapManager::alloc((Heaps::HeapType)0x2D, *sizeField);
            memset(*(void**)p, 0, *sizeField);
            *(char*)((char*)p + 8) = 0;
            *(char*)((char*)p + 9) = 0;
        }
        lbl_805A044C = p;
    }
    return (NtObj*)lbl_805A044C;
}

static inline u8 isReadyObj(NtObj* self) {
    u8 flag;
    if (self->hdr == 0) {
        flag = 0;
    } else {
        flag = self->flag;
        if (flag == 0 && fn_80351304((u8*)self->hdr + 0x10) != 0 &&
            fn_80351610((u8*)self->hdr + 0x10) != 0) {
            flag = 1;
        }
    }
    return flag;
}

static inline u8 isReady() {
    return isReadyObj(getInstance());
}

static inline s32 savePacket(void** out) {
    s32 r5;
    s32 flag;
    NtObj* self;
    if (out == 0) return 0;
    self = getInstance();
    if (self->hdr == 0) {
        flag = 0;
    } else {
        flag = self->flag;
        if (flag == 0 && fn_80351304((u8*)self->hdr + 0x10) != 0 &&
            fn_80351610((u8*)self->hdr + 0x10) != 0) {
            flag = 1;
        }
    }
    if (flag == 0) {
        r5 = 0;
    } else {
        fn_8035161C((u8*)self->hdr + 0x10);
        self->flag = 0;
        self->hdr->magic = 0x2804;
        s16 rev = srSystemGetRevisionNumber__Fv();
        NtPacket* t = self->hdr;
        t->rev = rev;
        self->hdr->pad6 = 0;
        self->hdr->crc = 0;
        s16 c = NETCalcCRC16(self->hdr, 0x2804);
        r5 = 1;
        self->hdr->crc = c;
        *out = self->hdr;
    }
    return r5;
}

extern "C" s32 fn_8014C26C(gfTask* arg0, s32 arg1, u8 arg2) {
    void* dst;
    s32 ok;
    s32 r5;

    if (*(s32*)((u8*)arg0 + 0x40) != 0) {
        return 0;
    }
    lbl_805A0448 += 1;
    ((u8*)arg0)[0x44] = arg2;
    if (fn_800305B0(2) == 0) {
        ok = 0;
    } else if (lbl_805A044C == 0) {
        ok = 0;
    } else if (NtBase::isMatchStatusOnline() == 0) {
        ok = 0;
    } else {
        ok = isReady() != 0;
    }
    if (ok != 0) {
        *(s32*)((u8*)arg0 + 0x40) = fn_80030548(arg1);
        if (*(s32*)((u8*)arg0 + 0x40) != 0) {
            dst = fn_80030DEC(*(s32*)((u8*)arg0 + 0x40), 2);
            if (dst != 0) {
                void* sp8 = 0;
                r5 = savePacket(&sp8);
                if (r5 != 0) {
                    memcpy(dst, sp8, 0x2804);
                    if (fn_80030F58(*(s32*)((u8*)arg0 + 0x40)) != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*(s32*)((u8*)arg0 + 0x40) != 0) {
        fn_800307B4();
        *(s32*)((u8*)arg0 + 0x40) = 0;
    }
    if (((u8*)arg0)[0x44] != 0) {
        arg0->exit();
    }
    lbl_805A0448 -= 1;
    return 0;
}
