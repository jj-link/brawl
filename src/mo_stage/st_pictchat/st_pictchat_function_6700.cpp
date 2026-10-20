#pragma force_active on
struct Pictchat {
    unsigned char pad0[0x150];
    unsigned char state;
    unsigned char pad151[0x294 - 0x151];
    unsigned char sound[8];
    int soundHandle;
};

extern "C" void stopSE__14snd3DGeneratorFll(void*, int, int);

extern "C" void fn_73_6700(Pictchat* self) {
    switch (self->state) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (self->soundHandle != -1) {
            stopSE__14snd3DGeneratorFll(self->sound, self->soundHandle, 0);
            self->soundHandle = -1;
        }
        break;
    }
}
