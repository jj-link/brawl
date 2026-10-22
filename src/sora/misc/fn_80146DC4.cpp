#pragma force_active on
extern "C" {
void* getInstance__8ipSwitchFv(void);
int fn_8013E380(void* p, unsigned int v);
extern int gUnk805a03d8;
extern char g_Network[];
}

extern "C" void fn_80146DC4(void) {
    int* net = (int*)g_Network;
    if (net != 0) {
        if (gUnk805a03d8 == 0) {
            net[0x14 / 4] = 2;
            return;
        }
        net[0x14 / 4] = 0;
        if (*(int*)getInstance__8ipSwitchFv() != 1) {
            net[0x18 / 4] = 1;
            return;
        }
        net[0x18 / 4] = 0x1E;
        fn_8013E380((void*)net[0x34 / 4], 0x65);
    }
}
