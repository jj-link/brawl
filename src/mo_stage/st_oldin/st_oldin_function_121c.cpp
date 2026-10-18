#include <ai/ai_mgr.h>
#pragma force_active on

extern "C" {
void fn_27_1F290C(aiMgr*, int);
void fn_53_1E88(void*, float);
void fn_53_159C(void*, float);
void fn_53_242C(void*, float);
void fn_53_2E0C(void*, float);
void fn_53_3370(void*, float);
}

extern "C" void fn_53_121C(void* arg, float value) {
    fn_27_1F290C(g_aiMgr, 0);
    fn_53_1E88(arg, value);
    fn_53_159C(arg, value);
    fn_53_242C(arg, value);
    fn_53_2E0C(arg, value);
    fn_53_3370(arg, value);
}