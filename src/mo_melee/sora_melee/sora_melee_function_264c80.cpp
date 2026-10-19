#pragma force_active on
extern "C" {
void __ct__9grGimmickFPCc(void*, const char*);
extern unsigned char lbl_27_data_55D80[];
}

struct grYakumono {
    unsigned char unk[0x14C];
    int unk14C;
};

extern "C" grYakumono* __ct__10grYakumonoFPCc(grYakumono* self, const char* name) {
    __ct__9grGimmickFPCc(self, name);
    self->unk14C = 0;
    *(void**)((char*)self + 0x3C) = lbl_27_data_55D80;
    return self;
}
