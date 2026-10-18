#pragma force_active on
extern "C" {
extern void* g_gfSceneRoot;
void fn_8000D1B8(void* scene, int type, void* data);
void fn_24_2E98(char* p);
}

void fn_24_2E98(char* p)
{
    fn_8000D1B8(g_gfSceneRoot, 8, *(void**)(*(char**)(p + 0x50) + 0x10));
}
