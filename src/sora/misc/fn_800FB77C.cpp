#pragma force_active on
extern "C" {
void fn_8000E590(void* base, int index, unsigned val);
extern void* g_gfSceneRoot;

void* fn_800FB77C(void* arg0, int arg1) {
    *(int*)arg0 = arg1;
    fn_8000E590(g_gfSceneRoot, arg1, 1);
    return arg0;
}
}
