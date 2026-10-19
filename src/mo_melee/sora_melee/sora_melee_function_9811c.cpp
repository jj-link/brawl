#pragma force_active on
class ecMgr {
public:
    void pushsetCurrentGroup(unsigned long group);
};

extern ecMgr* g_ecMgr;

extern "C" void fn_8005F794(ecMgr* mgr, unsigned long arg);

extern "C" {
void fn_27_9811C() {
    unsigned long group;
    g_ecMgr->pushsetCurrentGroup(group);
    fn_8005F794(g_ecMgr, 0);
}
}
