#pragma force_active on
extern "C" {
void* fn_27_14548C(const void* self);
void fn_27_60CDC(void*, void*, void*, float, float, float, float, float, float, float, float);
}
extern unsigned char g_ftCommonDataAccesser;

extern "C" void fn_27_151288(void* unused, void* a, void* b, void* c, float f1, float f2, float f3) {
    float v370;
    float v374;
    float v378;
    float v37c;
    v37c = *(float*)((unsigned char*)fn_27_14548C(&g_ftCommonDataAccesser) + 0x37c);
    v378 = *(float*)((unsigned char*)fn_27_14548C(&g_ftCommonDataAccesser) + 0x378);
    v374 = *(float*)((unsigned char*)fn_27_14548C(&g_ftCommonDataAccesser) + 0x374);
    v370 = *(float*)((unsigned char*)fn_27_14548C(&g_ftCommonDataAccesser) + 0x370);
    float v36c = *(float*)((unsigned char*)fn_27_14548C(&g_ftCommonDataAccesser) + 0x36c);
    fn_27_60CDC(a, b, c, f1, f2, f3, v36c, v370, v374, v378, v37c);
}
