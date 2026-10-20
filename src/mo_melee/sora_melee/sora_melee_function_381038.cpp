#pragma force_active on
extern "C" void* getFighter__9ftManagerFii(void*, int, int);
extern "C" void* g_ftManager;

extern "C" void* fn_27_381038(void* obj)
{
    return getFighter__9ftManagerFii(g_ftManager, *(int*)((char*)obj + 0x10c), -1);
}
