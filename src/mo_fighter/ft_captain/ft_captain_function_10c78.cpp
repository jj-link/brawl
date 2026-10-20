#pragma force_active on
class ecMgr;
extern ecMgr* g_ecMgr;

extern "C" void setVisibleGroup__5ecMgrFUlbUlUl(ecMgr*, bool, unsigned long, unsigned long);
extern "C" void fn_80060BB8(ecMgr*, unsigned int, unsigned int);
extern "C" void fn_80060B1C(ecMgr*, unsigned int, unsigned int);

extern "C" void fn_100_10C78(bool visible) {
    setVisibleGroup__5ecMgrFUlbUlUl(g_ecMgr, visible, 0x02000000, 0xFFFFFFFF);
    if (visible) {
        fn_80060BB8(g_ecMgr, 0x02000000, 0xFFFFFFFF);
    } else {
        fn_80060B1C(g_ecMgr, 0x02000000, 0xFFFFFFFF);
    }
}
