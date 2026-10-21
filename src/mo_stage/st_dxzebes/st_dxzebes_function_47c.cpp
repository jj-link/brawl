#pragma force_active on

struct efScreen;

struct efScreenHandle {
    signed char unk0;
    unsigned int isValid() const;
};

struct stCommonGimmick {
    char pad0[0x3C];
    char* unk3C;
    char pad40[0x1A0];
    char unk1E0[0x564];
    char unk744[0xAC];
    char unk7F0[0x209];
    efScreenHandle unk9F9;
};

extern "C" {
extern char lbl_84_data_1D0[];
extern const float lbl_84_rodata_A0;
extern efScreen* g_efScreen;

void releaseArchive__15stCommonGimmickFv(void*);
void fn_27_239F6C(void*);
void fn_8005E3C8(efScreen*, const unsigned char*, float);
void __dt__13grTenganEventFv(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_84_47C(stCommonGimmick* self, int flags) {
    if (self != 0) {
        self->unk3C = lbl_84_data_1D0;
        releaseArchive__15stCommonGimmickFv(self);
        fn_27_239F6C(&self->unk1E0[0]);
        if (self->unk9F9.isValid() == 1U) {
            unsigned char tmp = (unsigned char)self->unk9F9.unk0;
            fn_8005E3C8(g_efScreen, &tmp, lbl_84_rodata_A0);
            self->unk9F9.unk0 = (signed char)0xFF;
        }
        __dt__13grTenganEventFv(&self->unk7F0[0], -1);
        __dt__13grTenganEventFv(&self->unk744[0], -1);
        __dt__7stMeleeFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
