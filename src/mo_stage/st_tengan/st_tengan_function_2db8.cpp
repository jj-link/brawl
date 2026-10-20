#pragma force_active on
extern "C" {
extern const float lbl_60_rodata_0;
int getPhase__13grTenganEventCFv(const void*);
void* getGround__5StageFi(void*, int);
void endEntity__8grMadeinFv(void*);
void setEnableCollisionStatus__6GroundFb(void*, bool);
void setPhase__13grTenganEventFl(void*, long);
bool isReadyEnd__13grTenganEventCFv(const void*);
}

struct Tengan {
    char pad0[0x77c];
    char event[0xc];
    float timer;
    char pad1[0xe64 - 0x78c];
    float remaining;
    char pad2;
    unsigned char flag;
};

extern "C" bool fn_60_2DB8(Tengan* self) {
    self->remaining = self->timer;
    if (self->remaining < lbl_60_rodata_0)
        self->remaining = lbl_60_rodata_0;

    switch (getPhase__13grTenganEventCFv(self->event)) {
    case 0:
        if (self->flag == 1) {
            if (*((unsigned char*)getGround__5StageFi(self, 7) + 0x15c) == 3) {
                endEntity__8grMadeinFv(getGround__5StageFi(self, 27));
                setEnableCollisionStatus__6GroundFb(
                    getGround__5StageFi(self, 27), false);
                setPhase__13grTenganEventFl(self->event, 1);
            }
        } else {
            setPhase__13grTenganEventFl(self->event, 1);
        }
        break;

    case 1:
        if (lbl_60_rodata_0 == self->remaining &&
            isReadyEnd__13grTenganEventCFv(self->event) == true)
            return true;
        break;
    }

    return false;
}
