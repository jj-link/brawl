#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern unsigned char lbl_40_data_4DF8[];
}

struct grYakumonoWork {
    unsigned char unk[0x3C];
    void* unk3C;
    unsigned char unk2[0x150 - 0x40];
    int unk150;
    int unk154;
    int unk158;
    unsigned char unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    unsigned char unk170;
};

extern "C" grYakumonoWork* fn_40_1C0CC(grYakumonoWork* self, unsigned char param, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->unk150 = 0;
    self->unk3C = lbl_40_data_4DF8;
    self->unk154 = 0;
    self->unk158 = 0;
    self->unk15C = param;
    self->unk160 = 0;
    self->unk164 = 0;
    self->unk168 = 0;
    self->unk16C = 0;
    self->unk170 = 0;
    return self;
}
