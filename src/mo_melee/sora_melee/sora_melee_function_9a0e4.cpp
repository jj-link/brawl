#pragma force_active on
class ecTraceMgr {
public:
    void end(unsigned long a, unsigned long b, unsigned long c);
};

class ecMgr {
public:
    char pad[0x98];
    ecTraceMgr trace;
};

extern ecMgr* g_ecMgr;

extern "C" void fn_27_9A0E4(unsigned long x, unsigned long a, unsigned long b) {
    g_ecMgr->trace.end(a, b, 0);
}
