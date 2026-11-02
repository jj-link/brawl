#pragma force_active on
extern "C" {
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__9gfArchiveFv(void*);
void setPlayerPositionIndexSerial__7stMeleeFv(void*);
void fn_27_238DD8(void*, unsigned int);
void* memset(void* p, int c, unsigned long n);
extern char* g_GameGlobal;
extern char lbl_88_data_0[];
extern unsigned char lbl_88_data_46C[];
extern const float lbl_88_rodata_0;

void* fn_88_A4(void* self) {
    char* obj = (char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_88_data_0, 0x34);
    *(void**)(obj + 0x3c) = lbl_88_data_46C;
    __ct__9gfArchiveFv(obj + 0x5f0);
    __ct__9gfArchiveFv(obj + 0x670);
    __ct__9gfArchiveFv(obj + 0x6f0);
    __ct__9gfArchiveFv(obj + 0x770);

    *(char*)(obj + 0x1d8) = 0;
    *(float*)(obj + 0x1dc) = lbl_88_rodata_0;
    *(float*)(obj + 0x1e0) = lbl_88_rodata_0;
    *(float*)(obj + 0x1e4) = lbl_88_rodata_0;
    *(float*)(obj + 0x1e8) = lbl_88_rodata_0;
    *(int*)(obj + 0x1ec) = 0;
    *(int*)(obj + 0x1f0) = 0;
    *(char*)(obj + 0x1f4) = 0;
    *(char*)(obj + 0x1f5) = 0;
    *(float*)(obj + 0x1f8) = lbl_88_rodata_0;
    *(char*)(obj + 0x1fc) = 0;
    *(float*)(obj + 0x200) = lbl_88_rodata_0;
    *(char*)(obj + 0x204) = 0;
    *(float*)(obj + 0x208) = lbl_88_rodata_0;
    memset(obj + 0x20c, 0, 0x24);
    memset(obj + 0x230, 0, 0x24);
    memset(obj + 0x254, 0, 0x24);
    memset(obj + 0x278, 0, 0x14);
    memset(obj + 0x28c, 0, 0x14);

    *(char*)(obj + 0x2a0) = 0;
    *(char*)(obj + 0x2a1) = 0;
    *(char*)(obj + 0x2a2) = 0;
    *(float*)(obj + 0x2a4) = lbl_88_rodata_0;
    memset(obj + 0x2a8, 0, 0x90);
    memset(obj + 0x338, 0, 0x90);
    memset(obj + 0x3c8, 0, 0x30);
    memset(obj + 0x3f8, 0, 0x48);
    memset(obj + 0x440, 0, 0x120);
    memset(obj + 0x560, 0, 0x18);

    *(float*)(obj + 0x578) = lbl_88_rodata_0;
    *(float*)(obj + 0x57c) = lbl_88_rodata_0;
    *(float*)(obj + 0x580) = lbl_88_rodata_0;
    *(float*)(obj + 0x584) = lbl_88_rodata_0;
    *(float*)(obj + 0x588) = lbl_88_rodata_0;
    *(float*)(obj + 0x58c) = lbl_88_rodata_0;
    *(float*)(obj + 0x590) = lbl_88_rodata_0;
    memset(obj + 0x594, 0, 0x18);

    *(char*)(obj + 0x5c0) = 0;
    *(float*)(obj + 0x5ac) = lbl_88_rodata_0;
    *(float*)(obj + 0x5b0) = lbl_88_rodata_0;
    *(float*)(obj + 0x5b4) = lbl_88_rodata_0;
    *(float*)(obj + 0x5b8) = lbl_88_rodata_0;
    *(float*)(obj + 0x5bc) = lbl_88_rodata_0;
    *(float*)(obj + 0x5c4) = lbl_88_rodata_0;
    *(int*)(obj + 0x5c8) = 0;
    *(int*)(obj + 0x5cc) = 0;
    *(float*)(obj + 0x5d0) = lbl_88_rodata_0;
    *(char*)(obj + 0x5d4) = 0;
    *(char*)(obj + 0x5d5) = 0;
    *(char*)(obj + 0x5d6) = 0;
    memset(obj + 0x5d8, 0, 0xc);
    memset(obj + 0x5e4, 0, 0xc);

    *(int*)(obj + 0x7f0) = -1;
    *(int*)(obj + 0x7f4) = -1;
    *(int*)(obj + 0x7f8) = -1;
    *(int*)(obj + 0x7fc) = -1;
    *(int*)(obj + 0x800) = -1;
    *(int*)(obj + 0x804) = -1;

    char* gg = *(char**)(g_GameGlobal + 8);
    if (gg == 0) {
        return self;
    }
    if (*(unsigned char*)(gg + 0x63) != 0 || *(unsigned char*)(gg + 0x64) != 0) {
        setPlayerPositionIndexSerial__7stMeleeFv(self);
    } else {
        fn_27_238DD8(self, 0);
    }
    *(int*)(obj + 0x808) = 0;
    *(int*)(obj + 0x80c) = 0;
    return self;
}
}
