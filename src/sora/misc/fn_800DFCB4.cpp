#pragma force_active on
extern "C" {
void __construct_array(void*, void*, void*, int, int);
void fn_8007266C(void*);
void fn_800DFEC4(void*);
void fn_800DFE3C(void);
void fn_800DFE6C(void);
void setIdentity__6MatrixFv(void*);
extern char lbl_8045A38C[];
extern char lbl_8045A3A8[];
extern unsigned char lbl_805A02E4;
extern float lbl_805A23B0;
}

extern "C" void* fn_800DFCB4(char* self, unsigned char arg1) {
    float z = lbl_805A23B0;
    *(int*)(self + 0x290) = 0;
    *(char**)(self + 0x5D4) = lbl_8045A38C;
    *(int*)(self + 0x294) = 0;
    *(char**)(self + 0x2BC) = lbl_8045A3A8;
    *(float*)(self + 0x2FC) = z;
    *(int*)(self + 0x300) = 0;
    *(float*)(self + 0x2F0) = z;
    *(float*)(self + 0x2F4) = z;
    *(float*)(self + 0x2F8) = z;
    setIdentity__6MatrixFv(self + 0x2C0);
    lbl_805A02E4 = 1;
    z = lbl_805A23B0;
    *(char**)(self + 0x304) = lbl_8045A3A8;
    *(float*)(self + 0x344) = z;
    *(int*)(self + 0x348) = 0;
    *(float*)(self + 0x338) = z;
    *(float*)(self + 0x33C) = z;
    *(float*)(self + 0x340) = z;
    setIdentity__6MatrixFv(self + 0x308);
    lbl_805A02E4 = 1;
    z = lbl_805A23B0;
    *(char**)(self + 0x358) = lbl_8045A3A8;
    *(float*)(self + 0x398) = z;
    *(int*)(self + 0x39C) = 0;
    *(float*)(self + 0x38C) = z;
    *(float*)(self + 0x390) = z;
    *(float*)(self + 0x394) = z;
    setIdentity__6MatrixFv(self + 0x35C);
    lbl_805A02E4 = 1;
    fn_8007266C(self + 0x3A8);
    __construct_array(self + 0x3EC, (void*)fn_800DFE3C, (void*)fn_800DFE6C, 0x48, 4);
    z = lbl_805A23B0;
    *(char**)(self + 0x50C) = lbl_8045A3A8;
    *(float*)(self + 0x54C) = z;
    *(int*)(self + 0x550) = 0;
    *(float*)(self + 0x540) = z;
    *(float*)(self + 0x544) = z;
    *(float*)(self + 0x548) = z;
    setIdentity__6MatrixFv(self + 0x510);
    lbl_805A02E4 = 1;
    *(int*)(self + 0x570) = 0;
    *(int*)(self + 0x57C) = 0;
    *(int*)(self + 0x588) = 0;
    fn_800DFEC4(self);
    *(unsigned char*)(self + 0x1) = arg1;
    *(unsigned char*)(self + 0x3) = arg1;
    *(int*)(self + 0x4) = -1;
    return self;
}
