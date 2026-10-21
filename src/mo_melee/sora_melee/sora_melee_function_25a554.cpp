#pragma force_active on
extern "C" int OSReport(const char*, ...);
extern "C" int fn_800CC1BC(int);
extern "C" int g_muWifiInterfaceTask;
extern "C" char lbl_27_data_53814[];

struct State {
    unsigned char pad[0x14C];
    unsigned char a, b, c;
};

extern "C" unsigned char fn_27_25A554(const State* p) {
    if (p->a) {
        int t = g_muWifiInterfaceTask;
        switch (fn_800CC1BC(t)) {
        case 1:
            return 4;
        default:
            OSReport(lbl_27_data_53814, fn_800CC1BC(t));
        case 0:
        case 2:
            return 5;
        case 3:
            return 6;
        }
    } else {
        if (p->b)
            return 3;
        return p->c;
    }
}
