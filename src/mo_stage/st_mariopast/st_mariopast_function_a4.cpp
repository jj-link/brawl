#include <st/st_melee.h>
#include <cm/cm_controller_ai.h>
#include <string.h>
#pragma force_active on
extern "C" {
extern char lbl_48_data_0[];
extern char lbl_48_data_1C4[];
extern const float lbl_48_rodata_0;
void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
}
struct Flags { unsigned int top : 8; unsigned int rest : 24; };
extern "C" void* fn_48_A4(void* self) {
    char* p = (char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_48_data_0, 5);
    *(char**)(p + 0x3c) = lbl_48_data_1C4;
    *(float*)(p + 0x1e4) = lbl_48_rodata_0;
    memset(p + 0x1ec, 0, 0x18);
    memset(p + 0x204, 0, 0xc);
    memset(p + 0x210, 0, 0x9c);
    memset(p + 0x2ac, 0, 0x18);
    p[0x2c4] = 0;
    memset(p + 0x2c8, 0, 0x18);
    int off;
    int i = 0;
    off = 0;
    do {
        ((stCollisionWork*)(p + off + 0x2e0))->initialize();
        *(short*)((unsigned int)p + off + 0x2ec) = 4;
        *(char*)((unsigned int)p + off + 0x2ee) = 1;
        i++;
        off += 0x10;
    } while (i < 2);
    memset(p + 0x300, 0, 8);
    memset(p + 0x308, 0, 2);
    *(int*)(p + 0x1d8) = 0;
    p[0x30a] = 0;
    p[0x30b] = 0;
    p[0x30c] = 0;
    p[0x30d] = 0;
    p[0x30e] = 0;
    p[0x30f] = 0;
    p[0x310] = 0;
    *(float*)(p + 0x314) = lbl_48_rodata_0;
    *(float*)(p + 0x318) = lbl_48_rodata_0;
    if (g_cmAIController) {
        ((Flags*)((char*)g_cmAIController + 8))->top = 1;
    }
    return self;
}