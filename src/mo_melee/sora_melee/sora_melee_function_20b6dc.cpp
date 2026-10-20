#pragma force_active on
typedef signed char s8;

extern "C" float fn_27_21F1BC(s8*);
extern "C" char* g_aiMgr;
extern "C" const float lbl_27_rodata_2FDC;

extern "C" int fn_27_20B6DC(s8* self) {
    char* mgr = g_aiMgr;
    float d = fn_27_21F1BC(self);
    float pos = *(float*)((char*)self + 0x5c);
    if (pos - d < lbl_27_rodata_2FDC + *(float*)(mgr + 0x360) ||
        pos + d > *(float*)(mgr + 0x364) - lbl_27_rodata_2FDC) {
        return 1;
    }
    return 0;
}
