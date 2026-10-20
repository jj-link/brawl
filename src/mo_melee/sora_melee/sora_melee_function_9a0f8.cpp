#pragma force_active on
typedef unsigned long u32;

class ecTraceMgr {
public:
    void endGroup(u32, u32, u32);
};

struct ecMgr {
    char pad[0x98];
    ecTraceMgr trace;
};

extern ecMgr* g_ecMgr;

extern "C" void fn_27_9A0F8(char* self, u32 a, u32 b)
{
    g_ecMgr->trace.endGroup(*(u32*)(self + 0x48) | a, a | 0xffff00, b);
}
