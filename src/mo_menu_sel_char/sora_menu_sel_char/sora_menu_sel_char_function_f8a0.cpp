#pragma force_active on
extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern "C" void setFrameVisible__8MuObjectFf(void*, float);
extern "C" void setFrameTex__8MuObjectFf(void*, float);
extern "C" char lbl_10_data_6D8[];
extern "C" char lbl_10_data_6E0[];
extern "C" float lbl_10_rodata_450;
extern "C" char* g_GameGlobal;

extern "C" void fn_10_F8A0(char* self) {
    void* obj = *(void**)(self + 0x500);
    if (*(int*)(self + 0x5e4) > 1) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, *(void**)(*(char**)(self + 0x3d4) + 0x10), lbl_10_data_6D8);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, *(void**)(*(char**)(self + 0x3d0) + 0x10), lbl_10_data_6E0);
    }
    setFrameVisible__8MuObjectFf(*(void**)(self + 0x3cc), (float)*(int*)(self + 0x5e4));
    if ((int)*(unsigned char*)(*(char**)(g_GameGlobal + 0x10) + 4) == 7) {
        setFrameTex__8MuObjectFf(*(void**)(self + 0x3cc), lbl_10_rodata_450);
    }
}