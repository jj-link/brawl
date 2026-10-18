#pragma force_active on
extern "C" {
extern void* g_aiMgr;
void fn_27_1F1B68(void* mgr, void* obj, void* arg);
}

extern "C" void fn_27_124700(void* self, void* arg)
{
    char* p = *(char**)((char*)self + 4);
    fn_27_1F1B68(g_aiMgr, *(void**)(p + 0x58), arg);
}
