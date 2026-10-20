#pragma force_active on
struct ftCommonDataStruct {
    void* unk0;
    char* unk4;
};

extern ftCommonDataStruct g_ftCommonData;

extern "C" void* fn_27_145AA0(void* p);

extern "C" void* fn_27_1455E0(void* p) {
    g_ftCommonData.unk0 = p;
    g_ftCommonData.unk4 = (char*)p + 8;
    return fn_27_145AA0(&g_ftCommonData);
}
