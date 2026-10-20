#pragma force_active on
extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
void* fn_27_14548C(const void* self);
}

extern "C" float fn_27_10AD0C() {
    unsigned char* p = (unsigned char*)fn_27_14548C(g_ftCommonDataAccesser);
    return *(float*)(p + 0x210);
}
