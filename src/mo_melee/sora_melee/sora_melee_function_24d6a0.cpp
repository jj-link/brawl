#include <types.h>
#include <snd/snd_system.h>
#include <st/stage.h>
#pragma force_active on

extern "C" {
extern int lbl_27_data_4F050[];
extern const u8 lbl_27_rodata_4050[];
extern Stage* lbl_27_bss_5668;
}

struct Info {
    char pad0[8];
    u8 flags;
    char pad9[2];
    u8 flags2;
    char padc[0xe];
    u16 stage;
    char pad1c[0x7d];
    u8 type;
    u8 value;
    u8 index;
};

struct Status {
    char pad[0x2e];
    s8 active;
    char rest[0x27d];
};

struct Object {
    char pad0[0x44];
    Info* info;
    char pad48[0x2e];
    u8 disabled;
    char pad77[0x35];
    s32 sound;
    char padb0[0x1c];
    Status* status;
    char padd0[0xc];
    u8 flag;
    char paddd[0x158];
    u8 enabled;
    char pad236[2];
    u32 mask;
    u32 timer;
    s32 stateData;
    s32 state;
};

extern "C" void fn_27_24D6A0(Object* self) {
    Info* entry;
    int* data = lbl_27_data_4F050;
    u32 bit;
    s32 i;

    if (!self->enabled) {
        return;
    }
    switch (self->disabled) {
    case 0:
        break;
    default:
        return;
    }
    switch (self->state) {
    case 0:
        self->stateData = data[0x10c / 4];
        self->state = 0xbfd;
    case 0xbfd:
        switch ((self->info->flags >> 2) & 0x3f) {
        case 0:
        case 1:
        case 14:
        case 23:
        case 24:
        case 28:
        case 33: {
            u8 en = 0;
            if (self->flag && !((self->info->flags2 >> 5) & 1)) {
                en = 1;
            }
            self->enabled = en;
            break;
        }
        default:
            self->enabled = 0;
            break;
        }
        self->stateData = data[0x110 / 4];
        self->state = 0xc0e;
        return;
    case 0xc0e:
        self->mask = 0;
    case 0xc57:
    scan:
        for (i = 0; i < 4; i++) {
            entry = (Info*)((char*)self->info + i * 0x5c);
            if (entry->type != 3) {
                if (self->status[entry->index].active == 0) {
                    bit = 1 << i;
                    if (!(self->mask & bit)) {
                        self->mask |= bit;
                        if (entry->type == 0) {
                            g_sndSystem->playSE((SndID)(entry->value + 0x1fe8), self->sound, 0, 0, -1);
                            Stage* stage = lbl_27_bss_5668;
                            const u8* table = lbl_27_rodata_4050;
                            u8 vision[4] = { *table++, table[0], table[1], table[2] };
                            stage->setVision(vision[entry->value]);
                        } else {
                            g_sndSystem->playSE((SndID)0x1fec, self->sound, 0, 0, -1);
                        }
                        if (self->info->stage == 0x24) {
                            g_sndSystem->playSE((SndID)0x1d1e, -1, 0, 0, -1);
                        }
                        self->timer = 0;
                        goto delay1;
                    }
                } else {
                    goto clear;
                }
            }
            continue;
        inc41:
            self->timer++;
            self->stateData = data[0x114 / 4];
            self->state = 0xc41;
            return;
        case 0xc41:
        delay1:
            if (self->timer < 0x50) {
                goto inc41;
            }
            g_sndSystem->playSE((SndID)0x1fed, self->sound, 0, 0, -1);
            self->stateData = data[0x118 / 4];
            self->state = 0xc46;
            return;
        case 0xc46:
            self->timer = 0;
            goto check4c;
        inc4c:
            self->timer++;
            self->stateData = data[0x11c / 4];
            self->state = 0xc4c;
            return;
        case 0xc4c:
        check4c:
            if (self->timer < 0x50) {
                goto inc4c;
            }
            goto scan;
        clear:
            self->mask &= ~(1 << i);
        }
        self->stateData = data[0x120 / 4];
        self->state = 0xc57;
        return;
    }
}
