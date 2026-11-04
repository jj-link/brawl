#pragma force_active on
extern "C" {
extern char lbl_66_data_0[];
extern char lbl_66_data_208[];
extern const float lbl_66_rodata_0;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__9gfArchiveFv(void*);
void initialize__15stCollisionWorkFv(void*);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_66_A4(void* self) {
    char* p = (char*)self;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_66_data_0, 0x1d);
    *(void**)(p + 0x3c) = lbl_66_data_208;
    __ct__9gfArchiveFv(p + 0x288);
    __ct__9gfArchiveFv(p + 0x308);
    memset(p + 0x1d8, 0, 0x24);
    memset(p + 0x1fc, 0, 0x24);

    p[0x220] = 0;
    *(float*)(p + 0x224) = lbl_66_rodata_0;
    *(unsigned char*)(p + 0x228) = 0x80;
    p[0x229] = 1;
    p[0x22a] = 3;
    p[0x22b] = 5;
    *(float*)(p + 0x22c) = lbl_66_rodata_0;
    *(float*)(p + 0x234) = lbl_66_rodata_0;
    *(float*)(p + 0x23c) = lbl_66_rodata_0;
    p[0x238] = 1;
    p[0x239] = 0;
    *(int*)(p + 0x250) = -1;
    p[0x254] = 0;
    *(float*)(p + 0x258) = lbl_66_rodata_0;
    p[0x25c] = 1;

    initialize__15stCollisionWorkFv(p + 0x260);
    *(short*)(p + 0x26c) = 0x34;
    p[0x26e] = 1;
    p[0x270] = 0;
    *(float*)(p + 0x274) = lbl_66_rodata_0;
    *(int*)(p + 0x278) = 0;
    p[0x27c] = 1;
    p[0x27d] = 3;
    *(int*)(p + 0x280) = 0;
    *(int*)(p + 0x284) = 0;

    return self;
}
