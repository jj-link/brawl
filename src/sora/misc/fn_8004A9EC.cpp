#include <types.h>
#include <string.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <ip/ip_padconfig.h>
#include <ip/ip_network_producer.h>
#pragma force_active on

extern "C" {
void* fn_8004A468(void*, u32, gfPadStatus*, void*);
s32 fn_8004BCA4(void*, s32*, void*, void*);
void fn_8004BFA0(void*, void*, s32);
void fn_8004B2E4(void*, void*, s32);
void fn_8004B9CC(void*);
void* front__17ipNetworkProducerFv(void*);
void pop__17ipNetworkProducerFv(void*);
s32 randseed__Fv(void);
}

extern s32 lbl_805A00D4;

struct Entry {
    u16 f0;
    u8 f2;
    u8 f3;
};

struct Obj {
    s32 unk0;
    char pad4[0x38];
    s32 unk3C;
    char pad40[0x3C];
    s32 unk7C;
};

struct Self {
    s32 mode;            /* 0x00 */
    void* producer;      /* 0x04 */
    Entry entries[4];    /* 0x08 */
    Obj* obj18;          /* 0x18 */
    s32 f1C;             /* 0x1C */
    s32 f20;             /* 0x20 */
    u8 f24;              /* 0x24 */
};

extern "C" int fn_8004A9EC(Self* self) {
    gfPadStatus sp20;
    s32 sp10[4];
    s32 sp8;
    gfPadSystem* sys = g_gfPadSystem;

    if (self->mode == 0) {
        sys->updateGame();
        if ((sys->_0x34 >> 7) & 1) {
            for (u32 i = 0; i < 4; i++) {
                u8* base = (u8*)ipPadConfig::getInstance();
                s32 b5 = *(u8*)(base + i + 0xB5);
                if (b5 >= 0 && b5 < 8) {
                    sys->getGamePadStatus(b5 & 0xF, &sp20);
                    fn_8004A468(ipPadConfig::getInstance(), i, &sp20, &self->entries[i]);
                } else {
                    self->entries[i].f0 = 0;
                    self->entries[i].f3 = 0;
                    self->entries[i].f2 = 0;
                }
            }
        }
    } else {
        u8* prod = (u8*)self->producer;
        if (prod[0] == 0) {
            return 0;
        }
        u8* f = (u8*)front__17ipNetworkProducerFv(self->producer);
        self->entries[0].f0 = *(u16*)(f + 0);
        self->entries[0].f2 = f[2];
        self->entries[0].f3 = f[3];
        self->entries[1].f0 = *(u16*)(f + 4);
        self->entries[1].f2 = f[6];
        self->entries[1].f3 = f[7];
        self->entries[2].f0 = *(u16*)(f + 8);
        self->entries[2].f2 = f[10];
        self->entries[2].f3 = f[11];
        self->entries[3].f0 = *(u16*)(f + 12);
        self->entries[3].f2 = f[14];
        self->entries[3].f3 = f[15];
        pop__17ipNetworkProducerFv(self->producer);
        lbl_805A00D4 += 1;
    }

    Obj* obj = self->obj18;
    if (obj != NULL) {
        if (obj->unk0 == 1) {
            if ((((u32)((self->f24 >> 4) & 1)) != 1) && (fn_8004BCA4(self->obj18, &sp8, &self->f1C, &self->f20) != 0)) {
                fn_8004BFA0(self->obj18, &self->entries[0], sp8);
            }
        } else if (obj->unk0 == 2 && obj->unk3C != 1) {
            if ((self->f24 >> 5) & 1) {
                self->f24 = (u8)(self->f24 & 0xFFFFFFDF);
            } else {
                fn_8004B9CC(obj);
            }
            if (self->obj18->unk3C == 2) {
                self->obj18->unk7C = 0;
                memset(sp10, 0, 0x10);
                fn_8004B2E4(self->obj18, sp10, 4);
            } else {
                self->obj18->unk7C = randseed__Fv();
                fn_8004B2E4(self->obj18, &self->entries[0], 4);
            }
        }
    }
    return 1;
}
