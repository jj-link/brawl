#pragma force_active on
extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D6DC(void*, void*);

void fn_1_7ED4(void*, void* arg2) {
    fn_8000D6DC(g_gfSceneRoot, arg2);
}
}
