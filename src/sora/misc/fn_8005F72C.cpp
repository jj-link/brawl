#pragma force_active on

struct ecMgr {
    unsigned char pad0[0x43];
    signed char unk43;
    unsigned char pad44[0x3C];
    signed char unk80;
    unsigned char unk81;
};

extern "C" void popCurrentGroup__5ecMgrFv(ecMgr* mgr) {
    unsigned char r4 = mgr->unk81;
    if (r4 != 0) {
        mgr->unk81 = r4 - 1;
        if (mgr->unk81 == 0) {
            mgr->unk80 = 0;
            mgr->unk43 = 0;
        }
    }
}
