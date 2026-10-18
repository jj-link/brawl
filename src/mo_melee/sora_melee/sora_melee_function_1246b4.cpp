#pragma force_active on
extern "C" {
extern void* g_aiMgr;

void fn_27_1F1958(void* mgr, void* obj, signed char a, int b, int c);

void fn_27_1246B4(void* self, signed char arg)
{
    char* p = *(char**)((char*)self + 0x4);
    fn_27_1F1958(g_aiMgr, *(void**)(p + 0x58), arg, 0, -1);
}
}
