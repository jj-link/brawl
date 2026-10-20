#pragma force_active on
extern "C" void setAreaSleep__9stTriggerFb(void*, bool);
extern "C" void stopSE__14snd3DGeneratorFll(void*, int, int);

struct Pictchat {
    unsigned char pad0[0x150];
    unsigned char state;
    unsigned char pad151[0x294 - 0x151];
    unsigned char sound[8];
    int soundHandle;
    void* trigger;
};

extern "C" void fn_73_795C(Pictchat* self) {
    switch (self->state) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (self->trigger)
            setAreaSleep__9stTriggerFb(self->trigger, true);
        if (self->soundHandle != -1) {
            stopSE__14snd3DGeneratorFll(self->sound, self->soundHandle, 0);
            self->soundHandle = -1;
        }
        break;
    }
}
