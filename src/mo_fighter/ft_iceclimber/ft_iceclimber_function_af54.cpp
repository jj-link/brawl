#pragma force_active on
struct ftManager;
struct ftOwner;

extern "C" {
extern ftManager* g_ftManager;
ftOwner* getOwner__9ftManagerFi(ftManager*, int);
void* fn_27_10AFF8(ftManager*, int);
}

extern "C" ftOwner* fn_105_AF54(char* p)
{
    if (*(unsigned char*)(p + 0x1fe4c) == 1) {
        return (ftOwner*)fn_27_10AFF8(g_ftManager, *(int*)(p + 0x10c));
    }
    return getOwner__9ftManagerFi(g_ftManager, *(int*)(p + 0x10c));
}
