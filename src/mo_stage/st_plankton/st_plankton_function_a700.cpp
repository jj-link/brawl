#pragma force_active on

extern "C" void* fn_74_264C(void* self, const char* name);
extern "C" void setRot__9grGimmickFfff(void*, float, float, float);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" void strcpy(char*, const char*);
extern "C" const float lbl_74_rodata_138;
extern "C" char lbl_74_data_287C[];
extern "C" const char lbl_74_data_2878[];

struct Plankton {
    char pad[0x3C];
    void* unk3C;
    char pad40[0x118];
    char unk158[0x80];
    char unk1D8;
    char unk1D9;
    char pad1DA[2];
    float unk1DC;
    char unk1E0;
    char unk1E1;
    char pad1E2[2];
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
};

extern "C" Plankton* fn_74_A700(Plankton* self, const char* name) {
    fn_74_264C(self, name);
    self->unk3C = &lbl_74_data_287C;
    setRot__9grGimmickFfff(self, lbl_74_rodata_138, lbl_74_rodata_138, lbl_74_rodata_138);
    strcpy(self->unk158, lbl_74_data_2878);
    self->unk1D8 = 0;
    self->unk1D9 = 0x64;
    self->unk1DC = lbl_74_rodata_138;
    self->unk1E0 = 1;
    self->unk1E1 = 0;
    self->unk1E4 = 0;
    self->unk1E8 = 0;
    self->unk1EC = 0;
    self->unk1F0 = 0;
    self->unk1F4 = 0;
    self->unk1F8 = 0;
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 0xf);
    setCalcuCallbackRoot__9grGimmickFUl(self, 0x20);
    return self;
}
