#pragma force_active on
extern "C" void setAreaSleep__9stTriggerFb(void* trigger, bool sleep);

struct Sub {
    char pad[0x28];
    unsigned char count;
};

struct Obj {
    char pad0[0x9c];
    Sub* sub;
    char pad1[0x3a4 - 0xa0];
    unsigned char state;
    char pad2[0x3a8 - 0x3a5];
    void* trigger;
    char pad3[0x428 - 0x3ac];
    unsigned char* entries;
};

extern "C" void fn_68_1C8C(Obj* self) {
    if (self->state == 8) {
        setAreaSleep__9stTriggerFb(self->trigger, false);
        if (self->sub != 0) {
            unsigned char i;
            unsigned char n = self->sub->count;
            for (i = 0; i != n; i++) {
                unsigned char* e = self->entries + i * 0x28;
                if (e[0x19] == 1) {
                    e[0x24] = 8;
                }
            }
            self->state = 0xd;
        }
    } else {
        setAreaSleep__9stTriggerFb(self->trigger, true);
    }
}
