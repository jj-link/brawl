#pragma force_active on
extern "C" {
extern const char lbl_72_data_0[];
extern const float lbl_72_rodata_0;
extern const float lbl_72_rodata_4;
extern unsigned char lbl_72_data_1D8[];
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void setIdentity__6MatrixFv(void*);
void* memset(void*, int, unsigned int);
}

extern "C" unsigned char* fn_72_A4(unsigned char* self) {
    unsigned int off;
    unsigned int i;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_72_data_0, 0x23);
    self[0x1db] = 0;
    *reinterpret_cast<unsigned char**>(self + 0x3c) = lbl_72_data_1D8;
    self[0x1d8] = 5;
    self[0x1d9] = 5;
    self[0x1da] = 5;
    self[0x1dc] = 0;
    self[0x1dd] = 0;
    self[0x1de] = 0;
    *reinterpret_cast<float*>(self + 0x1e0) = lbl_72_rodata_0;
    self[0x1e4] = 0;
    memset(self + 0x1e5, 0, 3);
    float f31 = lbl_72_rodata_4;
    i = 0;
    for (; i < 3; i++) {
        off = (unsigned char)i * 0x38;
        unsigned char* entry = self + off;
        entry[0x1e8] = 5;
        entry[0x1e9] = 3;
        setIdentity__6MatrixFv(entry + 0x1ec);
        *reinterpret_cast<float*>((unsigned int)self + off + 0x21c) = f31;
    }
    self[0x2c0] = 5;
    memset(self + 0x290, 0, 0x30);
    return self;
}
