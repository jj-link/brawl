#pragma force_active on
struct ftManager;
struct ftOwner;

extern "C" {
extern ftManager* g_ftManager;
ftOwner* getOwner__9ftManagerFi(ftManager*, int);
}

extern "C" ftOwner* fn_27_130410(void* p)
{
    return getOwner__9ftManagerFi(g_ftManager, *(int*)((char*)p + 0x10c));
}
