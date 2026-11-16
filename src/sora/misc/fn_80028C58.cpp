#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_thread.h>
#include <revolution/OS/OSThread.h>

#pragma force_active on

extern "C" void fn_801E74C8(int);
extern "C" void fn_80215E68();
extern "C" void fn_80218D64();
extern "C" void fn_80218D60(void*, void*);
extern "C" void* fn_80028808(unsigned long);
extern "C" int fn_80028818(void*, void*);
extern "C" void fn_80227E54();
extern "C" void fn_8022555C(int, int);
extern "C" void fn_80225570(int, float, float);
extern "C" int fn_8021C938(int);
extern "C" void fn_8021C9AC(int, int, int);
extern "C" void fn_8021A118(int, void*);
extern "C" void fn_80028B74();

extern "C" char __vt__8gfThread[];
extern "C" char __vt__15gfPadReadThread[];

extern float lbl_805A1528;
extern float lbl_805A1530;
extern float lbl_805A1534;

static inline void initPad(gfPadStatus& s, float zero) {
    s.m_buttonsPressedThisFrame2.bits = 0;
    s.m_buttonsReleasedThisFrame.bits = 0;
    s.m_buttonsPressedThisFrame.bits = 0;
    s.m_buttonsHeld.bits = 0;
    s.m_buttonsCurrentFrame2.bits = 0;
    s.m_buttonsCurrentFrame.bits = 0;
    s.m_stickY = 0;
    s.m_stickX = 0;
    s.m_subStickY = 0;
    s.m_subStickX = 0;
    s.m_rTriggerAnalog = 0;
    s.m_lTriggerAnalog = 0;
    s._0x37 = 0;
    s._0x36 = 0;
    s._0x24 = zero;
    s._0x20 = zero;
    s._0x1c = zero;
    s._0x18 = zero;
    s._0x2c = zero;
    s._0x28 = zero;
    s.m_error = gfPadError::NO_CONTROLLER;
    s.m_controllerType = gfPadType::GCC;
}

struct PadOptionBits {
    u8 upper : 4;
    u8 useQueue : 1;
    u8 lower : 3;
    u8 gameDataBusy : 1;
    u8 motorEnabled : 1;
    u8 remaining : 6;
};

gfPadSystem::gfPadSystem() {
    gfPadReadThread* thread;
    PadOptionBits& options = *(PadOptionBits*)&_0x34;
    options.upper = 0;
    options.useQueue = 1;
    options.lower = 0;
    options.gameDataBusy = 0;
    options.motorEnabled = 1;
    *(int*)_0x30 = 0;
    m_debugPadMask = 0xFFFF;
    m_sysExcludedPadMask = 0;
    m_gamePadMask = 0xFFFF;
    _0x3e = 0;
    m_padQueue = 0;
    *(int*)_0x944 = 0;
    _0xb48 = 60;
    _0xb49 = 3;
    m_motorMask = 0;
    _0xb4c[0] = 0;
    _0xb4c[1] = 0;
    m_gfRumble = 0;
    m_gameData = 0;
    *(int*)_0xb70 = 0;

    fn_801E74C8(11);
    fn_80215E68();
    fn_80218D64();
    fn_80218D60((void*)fn_80028808, (void*)fn_80028818);
    fn_80227E54();
    fn_8022555C(0, 0x7F);

    for (int i = 0; i <= 3; i++) {
        fn_80225570(i, lbl_805A1530, lbl_805A1534);
    }

    if (fn_8021C938(0)) fn_8021C9AC(0, 0, 0);
    if (fn_8021C938(1)) fn_8021C9AC(1, 0, 0);
    if (fn_8021C938(2)) fn_8021C9AC(2, 0, 0);
    if (fn_8021C938(3)) fn_8021C9AC(3, 0, 0);

    for (int i = 0; i < 4; i++) {
        fn_8021A118(0, (void*)fn_80028B74);
    }

    float zero = lbl_805A1528;
    initPad(m_sysPadMerged, zero);
    initPad(m_debugPadMerged, zero);
    initPad(m_gamePadMerged, zero);

    for (int i = 0; i < 4; i++) {
        initPad(m_systemPads[i], zero);
        initPad(m_gameGcnPads[i], zero);
    }

    zero = lbl_805A1528;
    for (int i = 4; i < 8; i++) {
        initPad(m_systemPads[i], zero);
        m_systemPads[i].m_controllerType = gfPadType::WIIMOTE;
        initPad(m_gameWiiPads[i - 4], zero);
        m_gameWiiPads[i - 4].m_controllerType = gfPadType::WIIMOTE;
    }

    zero = lbl_805A1528;
    for (int i = 0; i < 8; i++) {
        initPad(m_debugGcnPads[i], zero);
    }

    zero = lbl_805A1528;
    for (int i = 0; i < 8; i++) {
        initPad(m_gameGcnPads[i], zero);
    }

    u8* p = (u8*)this;
    u8* q;
    for (int i = 0; i < 8; i++, p += 0x20) {
        for (int j = 0; j < 0x20; j++) {
            q = p + j;
            q[0x948] = 0;
            q[0xA48] = 0;
        }
    }

    gfPadStatusQueue* queue = new ((Heaps::HeapType)1) gfPadStatusQueue();
    m_padQueue = queue;

    thread = (gfPadReadThread*)operator new(0x348, (Heaps::HeapType)1);
    if (thread != 0) {
        *(void**)thread = __vt__8gfThread;
        thread->createThread(thread, 0xE, 0x1200, (Heaps::HeapType)1);
        *(void**)thread = __vt__15gfPadReadThread;
        ((u8*)thread)[0x340] = 1;
    }

    m_controllerThread = thread;
    g_gfPadSystem = this;
    OSResumeThread((OSThread*)((char*)m_controllerThread + 8));
}
