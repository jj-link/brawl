#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void* g_cmAIController;

void* fn_8009F744(void* arg0, int arg1) {
    if (arg0 != 0) {
        g_cmAIController = 0;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
