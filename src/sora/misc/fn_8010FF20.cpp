#pragma force_active on
extern "C" {
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, void*);
extern int lbl_8045D908[4];
extern void* g_gfPadSystem;

struct gfPadStatus {
    unsigned int _0x0;
    unsigned int _0x4;
    unsigned int _0x8;
    unsigned int m_buttonsPressedThisFrame;
    unsigned int _0x10;
    unsigned int _0x14;
    unsigned int _0x18;
    unsigned int _0x1c;
    unsigned int _0x20;
    unsigned int _0x24;
    unsigned int _0x28;
    unsigned int _0x2c;
    unsigned int _0x30;
    unsigned int _0x34;
    unsigned int _0x38;
    unsigned int m_controllerType;
};

int fn_8010FF20(unsigned int mask) {
    int i = 0;
    while (i < 8) {
        if (mask & (1 << i)) {
            gfPadStatus status;
            getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, i, &status);
            if (status.m_buttonsPressedThisFrame & lbl_8045D908[status.m_controllerType])
                return 1;
        }
        i++;
    }
    return 0;
}
}
