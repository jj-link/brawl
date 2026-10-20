#pragma force_active on
extern "C" {
extern char lbl_27_data_4ACAC[];
extern unsigned char lbl_27_data_4AE20[];
extern const float lbl_27_rodata_3748[];

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);

void* fn_27_22B578(void* self) {
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_27_data_4ACAC, 0x28);
    *(void**)((char*)self + 0x3C) = lbl_27_data_4AE20;
    *(int*)((char*)self + 0x268) = 0;
    *(int*)((char*)self + 0x26C) = 0;
    *(unsigned char*)((char*)self + 0x270) = 0;
    *(int*)((char*)self + 0x274) = 0;
    *(int*)((char*)self + 0x278) = 0;
    *(float*)((char*)self + 0x2A0) = lbl_27_rodata_3748[0];
    *(float*)((char*)self + 0x290) = lbl_27_rodata_3748[0];
    *(float*)((char*)self + 0x294) = lbl_27_rodata_3748[0];
    *(float*)((char*)self + 0x298) = lbl_27_rodata_3748[0];
    *(float*)((char*)self + 0x29C) = lbl_27_rodata_3748[0];
    return self;
}
}
