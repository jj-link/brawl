#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E604(void*);

unsigned int fn_800514C4(unsigned int arg0) {
    unsigned int* p = (unsigned int*)fn_8004E604(g_GameGlobal);
    unsigned int v = *p;
    unsigned int r = v >= arg0 ? v - arg0 : 0;
    *p = r;
    return r;
}
}
