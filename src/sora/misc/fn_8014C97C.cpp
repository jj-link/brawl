#include <types.h>
#pragma force_active on

struct Hdr {
    u16 magic;
    u16 crc;
    u16 rev;
    u8 pad6;
    u8 pad7;
};

struct Obj {
    Hdr* hdr;
    u8 pad4[4];
    u8 flag;
};

extern "C" {
    s16 NETCalcCRC16(void*, s32, void*);
    s32 fn_80351304(void*);
    u32 fn_80351610(void*);
    void fn_8035161C(void*);
    s16 srSystemGetRevisionNumber__Fv(void);
}

extern "C" s32 fn_8014C97C(Obj* self, Hdr** outHdr, s32* outMagic) {
    s32 r30;
    if (self->hdr == 0) {
        r30 = 0;
    } else {
        r30 = self->flag;
        if (r30 == 0 && fn_80351304((u8*)self->hdr + 0x10) != 0 &&
            fn_80351610((u8*)self->hdr + 0x10) != 0) {
            r30 = 1;
        }
    }
    if (r30 == 0) {
        return 0;
    }
    fn_8035161C((u8*)self->hdr + 0x10);
    self->flag = 0;
    self->hdr->magic = 0x2804;
    s16 rev = srSystemGetRevisionNumber__Fv();
    Hdr* t = self->hdr;
    t->rev = rev;
    self->hdr->pad6 = 0;
    self->hdr->crc = 0;
    self->hdr->crc = NETCalcCRC16(self->hdr, 0x2804, t);
    *outHdr = self->hdr;
    *outMagic = 0x2804;
    return 1;
}
