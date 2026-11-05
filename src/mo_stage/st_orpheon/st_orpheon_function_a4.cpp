#pragma force_active on
#include <st/st_melee.h>
#include <gr/gr_tengan_event.h>
#include <st/se_util.h>

extern "C" {
extern char lbl_55_data_60[];
extern char lbl_55_data_210[];
extern char lbl_55_data_4A8[];
extern char lbl_55_data_468[];
extern const float lbl_55_rodata_0;
extern const float lbl_55_rodata_4;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__13grTenganEventFv(void*);
void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);

void* fn_55_A4(void* self) {
    unsigned char* p = (unsigned char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_55_data_60, 12);
    *(void**)(p + 0x3c) = lbl_55_data_210;
    __ct__13grTenganEventFv(p + 0x1d8);
    __ct__13grTenganEventFv(p + 0x284);
    __ct__13grTenganEventFv(p + 0x330);
    __ct__13grTenganEventFv(p + 0x3dc);
    __ct__13grTenganEventFv(p + 0x488);
    __ct__13grTenganEventFv(p + 0x534);
    unsigned char* a = p + 0x614;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(a, a + 0x20, 3, a + 0x44, 3);
    *(void**)a = lbl_55_data_4A8;
    unsigned char* b = p + 0x688;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(b, b + 0x20, 1, b + 0x2c, 1);
    *(void**)b = lbl_55_data_468;
    *(float*)(p + 0x5e0) = lbl_55_rodata_0;
    *(float*)(p + 0x5e4) = lbl_55_rodata_4;
    *(float*)(p + 0x5e8) = lbl_55_rodata_0;
    *(float*)(p + 0x5ec) = lbl_55_rodata_0;
    *(float*)(p + 0x5f0) = lbl_55_rodata_0;
    *(float*)(p + 0x5f4) = lbl_55_rodata_0;
    *(float*)(p + 0x5f8) = lbl_55_rodata_0;
    *(float*)(p + 0x5fc) = lbl_55_rodata_0;
    *(float*)(p + 0x600) = lbl_55_rodata_0;
    *(float*)(p + 0x604) = lbl_55_rodata_0;
    *(float*)(p + 0x608) = lbl_55_rodata_0;
    *(float*)(p + 0x60c) = lbl_55_rodata_0;
    *(float*)(p + 0x610) = lbl_55_rodata_0;
    p[0x6c4] = 0;
    p[0x6c5] = (p[0x6c5] | 0x80) & ~0x40;
    p[0x6c6] = 0;
    p[0x6c7] = 0;
    return self;
}
}