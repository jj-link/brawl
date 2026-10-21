#pragma force_active on
struct itManager {
    unsigned char pad0[0x44];
    unsigned char unk44;
    unsigned char pad45;
    unsigned char unk46;
    unsigned char unk47;
};

extern "C" void* getInstance__9itManagerFv();

extern "C" void fn_27_23EC18(itManager* self) {
    if (self->unk46 == 0) {
        return;
    }
    if (getInstance__9itManagerFv() == 0) {
        return;
    }
    switch (self->unk44) {
    case 0:
        self->unk44 = 1;
        break;
    case 1:
        self->unk44 = 2;
        break;
    case 2:
        self->unk44 = 3;
        break;
    case 3:
        if (self->unk47 == 1) {
            self->unk44 = 5;
        }
        break;
    case 5:
        if (self->unk47 == 1) {
            self->unk44 = 6;
        } else {
            self->unk44 = 0;
        }
        break;
    }
}
