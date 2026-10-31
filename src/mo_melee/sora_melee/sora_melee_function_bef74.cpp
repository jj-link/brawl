#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern void* g_gfSceneRoot;
void fn_80010208(void* root, void* p);
}

extern "C" void fn_27_BEF74(u8* p)
{
    if (p[0x148] == 0xff) {
        return;
    }
    fn_80010208(g_gfSceneRoot, p + 0x148);
}
