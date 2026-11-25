#pragma force_active on

#include <st/st_melee.h>
#include <gr/gr_tengan_event.h>
#include <cstring>

extern "C" {
extern const char lbl_84_data_98[];
extern char lbl_84_data_1D0[];
extern const float lbl_84_rodata_0[];

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__13grTenganEventFv(void*);
void* __dummy_unused__(void*);

stMelee* fn_84_A4(stMelee* self) {
    signed char* p = (signed char*)self;
    const float* const k = lbl_84_rodata_0;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_84_data_98, 0x32);
    *(void**)(p + 0x3c) = lbl_84_data_1D0;
    __ct__13grTenganEventFv(p + 0x744);
    __ct__13grTenganEventFv(p + 0x7f0);

    p[0x9f9] = -1;
    memset(p + 0x220, 0, 0x280);
    memset(p + 0x1f0, 0, 0x30);
    memset(p + 0x4a0, 0, 0x18);
    memset(p + 0x4b8, 0, 0x14);
    memset(p + 0x4cc, 0, 2);

    p[0x89c] = 0;
    unsigned int b = (unsigned char)p[0x1d8];
    b = (b & ~0x80) | 0x40;
    p[0x1d8] = (unsigned char)b;
    *(float*)(p + 0x1dc) = k[0];
    p[0x9f9] = -1;

    *(float*)(p + 0x8a0) = k[1];
    *(float*)(p + 0x8a4) = k[2];
    *(float*)(p + 0x8a8) = k[3];
    *(float*)(p + 0x8ac) = k[1];
    *(float*)(p + 0x8b0) = k[4];
    *(float*)(p + 0x8b4) = k[3];
    *(float*)(p + 0x8b8) = k[5];
    *(float*)(p + 0x8bc) = k[6];
    *(float*)(p + 0x8c0) = k[7];
    *(float*)(p + 0x8c4) = k[5];
    *(float*)(p + 0x8c8) = k[8];
    *(float*)(p + 0x8cc) = k[7];
    *(float*)(p + 0x8d0) = k[5];
    *(float*)(p + 0x8d4) = k[9];
    *(float*)(p + 0x8d8) = k[10];
    *(float*)(p + 0x8dc) = k[5];
    *(float*)(p + 0x8e0) = k[2];
    *(float*)(p + 0x8e4) = k[10];
    *(float*)(p + 0x8e8) = k[11];
    *(float*)(p + 0x8ec) = k[12];
    *(float*)(p + 0x8f0) = k[13];
    *(float*)(p + 0x8f4) = k[11];
    *(float*)(p + 0x8f8) = k[14];
    *(float*)(p + 0x8fc) = k[13];
    *(float*)(p + 0x900) = k[15];
    *(float*)(p + 0x904) = k[9];
    *(float*)(p + 0x908) = k[16];
    *(float*)(p + 0x90c) = k[15];
    *(float*)(p + 0x910) = k[17];
    *(float*)(p + 0x914) = k[16];
    *(float*)(p + 0x918) = k[18];
    *(float*)(p + 0x91c) = k[19];
    *(float*)(p + 0x920) = k[20];
    *(float*)(p + 0x924) = k[18];
    *(float*)(p + 0x928) = k[21];
    *(float*)(p + 0x92c) = k[20];
    *(float*)(p + 0x930) = k[22];
    *(float*)(p + 0x934) = k[23];
    *(float*)(p + 0x938) = k[24];
    *(float*)(p + 0x93c) = k[22];
    *(float*)(p + 0x940) = k[25];
    *(float*)(p + 0x944) = k[24];
    *(float*)(p + 0x948) = k[26];
    *(float*)(p + 0x94c) = k[9];
    *(float*)(p + 0x950) = k[27];
    *(float*)(p + 0x954) = k[26];
    *(float*)(p + 0x958) = k[2];
    *(float*)(p + 0x95c) = k[27];
    *(float*)(p + 0x960) = k[28];
    *(float*)(p + 0x964) = k[29];
    *(float*)(p + 0x968) = k[30];
    *(float*)(p + 0x96c) = k[28];
    *(float*)(p + 0x970) = k[31];
    *(float*)(p + 0x974) = k[30];
    *(float*)(p + 0x978) = k[32];
    *(float*)(p + 0x97c) = k[33];
    *(float*)(p + 0x980) = k[34];
    *(float*)(p + 0x984) = k[32];
    *(float*)(p + 0x988) = k[35];
    *(float*)(p + 0x98c) = k[34];
    *(float*)(p + 0x990) = k[36];
    *(float*)(p + 0x994) = k[37];
    *(float*)(p + 0x998) = k[10];
    *(float*)(p + 0x99c) = k[36];
    *(float*)(p + 0x9a0) = k[38];
    *(float*)(p + 0x9a4) = k[10];
    *(float*)(p + 0x9a8) = k[39];
    *(float*)(p + 0x9ac) = k[40];
    *(float*)(p + 0x9b0) = k[41];
    *(float*)(p + 0x9b4) = k[39];
    *(float*)(p + 0x9b8) = k[42];
    *(float*)(p + 0x9bc) = k[41];
    *(float*)(p + 0x9c0) = k[43];
    *(float*)(p + 0x9c4) = k[44];
    *(float*)(p + 0x9c8) = k[45];
    *(float*)(p + 0x9cc) = k[43];
    *(float*)(p + 0x9d0) = k[46];
    *(float*)(p + 0x9d4) = k[45];
    *(float*)(p + 0x9d8) = k[47];
    *(float*)(p + 0x9dc) = k[48];
    *(float*)(p + 0x9e0) = k[34];
    *(float*)(p + 0x9e4) = k[47];
    *(float*)(p + 0x9e8) = k[12];
    *(float*)(p + 0x9ec) = k[34];
    *(float*)(p + 0x9f0) = k[10];

    p[0x9f8] = 1;
    return self;
}
}
