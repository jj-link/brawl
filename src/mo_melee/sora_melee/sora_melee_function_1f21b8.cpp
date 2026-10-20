#pragma force_active on
class aiMgr;
extern aiMgr* g_aiMgr;

extern "C" aiMgr* fn_27_1F21B8()
{
    return *reinterpret_cast<aiMgr**>(
        reinterpret_cast<char*>(g_aiMgr) + 0x13C);
}
