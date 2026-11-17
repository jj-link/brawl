#include <ip/ip_switch.h>
#pragma force_active on

extern "C" {
void fn_80016900(void*, unsigned int, unsigned int);
void fn_8010FE58(void*, void*);
void fn_27_255624(void*);
void fn_8002C060(void*);
void fn_8002C428(void*);
void stopMotorAllForce__11gfPadSystemFv(void*);
void* fn_80076714(void*, int, int);
int fn_800CCF1C(int);
int fn_800D1BC8(int);
void fn_800D1ADC(int, int);
void fn_800DCF74(void*);
void* fn_800DD02C(void*, void*);
void fn_800DF68C(void*, int, int, int, int);
int fn_8010FF20(int);
int fn_8010FFBC(int);
void* fn_80110058(int);

void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void OSReport(const char*, ...);
extern void* g_IfMngr;
extern void* g_gfApplication;
extern void* g_gfPadSystem;
extern void* g_sndSystem;
extern int g_muWifiInterfaceTask;
extern unsigned char lbl_27_bss_59D8;
extern char lbl_27_data_4EDD8[];
}

inline char* getInstance__8ipSwitchFv(char*) { return (char*)ipSwitch::getInstance(); }

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27(int);
};

extern "C" unsigned char fn_27_2485A8(char* p) {
    char* d = lbl_27_data_4EDD8;
    void* r3 = p;
    void* t;
    void* q;
    void* ifm;
    int r29, r28, r27;
    int r27b, r28b, r29b;
    int sp8;
    int state;

    if (((unsigned int)*(int*)((char*)g_gfApplication + 0xEC) >> 27) & 0x10) {
        return 0;
    }
    state = *(int*)(p + 0xB8);
    switch (state) {
    case 0x0:
        *(int*)(p + 0xB4) = *(int*)(d + 0xE0);
        *(int*)(p + 0xB8) = 0x274;
    case 0x274:
        fn_80016900(g_gfApplication, 1, 1);
        fn_8010FE58(p + 0xC0, p + 0xC4);
        t = *(void**)(p + 0x4C);
        if (t != 0) {
            ((Object_vptr_3c*)t)->slot27(1);
        }
        lbl_27_bss_59D8 = 0;
        t = *(void**)(p + 0x50);
        if (t != 0) {
            fn_27_255624(t);
        }
        *(int*)(p + 0xB4) = *(int*)(d + 0xE4);
        *(int*)(p + 0xB8) = 0x28C;
        break;
    case 0x28C:
        fn_8002C060(*(void**)((char*)g_gfPadSystem + 0xB68));
        fn_8002C428(*(void**)((char*)g_gfPadSystem + 0xB68));
        stopMotorAllForce__11gfPadSystemFv(g_gfPadSystem);
        r3 = fn_80076714(g_sndSystem, 0, 0);
        *(int*)(p + 0xC8) = 0x258;
    case 0x2C3:
    block_25:
        r29 = 0;
        r28 = 0;
        r27 = 0;
        r3 = getInstance__8ipSwitchFv((char*)r3);
        if (r3 != 0) {
            r3 = getInstance__8ipSwitchFv((char*)r3);
            if (*(void**)((char*)r3 + 0x18) != 0) {
                r27 = 1;
            }
        }
        if (r27 != 0) {
            r3 = *(void**)((char*)getInstance__8ipSwitchFv((char*)r3) + 0x18);
            if (*(unsigned char*)((char*)r3 + 0x3B) == 0) {
                r28 = 1;
            }
        }
        if (r28 != 0) {
            q = *(void**)((char*)getInstance__8ipSwitchFv((char*)r3) + 0x18);
            q = *(void**)((char*)q + 0x24);
            if (*(unsigned short*)((char*)q + 0x6) <= 0x2B98) {
                r29 = 1;
            }
        }
        ifm = g_IfMngr;
        fn_800DF68C(*(void**)((char*)ifm + 0x44), 1, *(int*)(p + 0xC0), r29, *(unsigned char*)((char*)ifm + 0xA8));
        q = fn_80110058(*(int*)(p + 0xC4));
        if (q != 0) {
            r27b = 0;
            r28b = 0;
            r29b = 0;
            r3 = getInstance__8ipSwitchFv((char*)q);
            if (r3 != 0) {
                r3 = getInstance__8ipSwitchFv((char*)r3);
                if (*(void**)((char*)r3 + 0x18) != 0) {
                    r29b = 1;
                }
            }
            if (r29b != 0) {
                r3 = *(void**)((char*)getInstance__8ipSwitchFv((char*)r3) + 0x18);
                if (*(unsigned char*)((char*)r3 + 0x3B) == 0) {
                    r28b = 1;
                }
            }
            if (r28b != 0) {
                q = *(void**)((char*)getInstance__8ipSwitchFv((char*)r3) + 0x18);
                q = *(void**)((char*)q + 0x24);
                if (*(unsigned short*)((char*)q + 0x6) <= 0x2B98) {
                    r27b = 1;
                }
            }
            if (r27b != 0) {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, 0x10000, 0, 0, -1);
                fn_800DF68C(*(void**)((char*)g_IfMngr + 0x44), 0, 0, 1, *(unsigned char*)((char*)g_IfMngr + 0xA8));
                goto block_60;
            } else {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 3, 0x10000, 0, 0, -1);
                goto block_47;
            }
        } else {
block_47:
            if (fn_8010FFBC(*(int*)(p + 0xC4)) != 0) {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, 0x10000, 0, 0, -1);
                fn_800DF68C(*(void**)((char*)g_IfMngr + 0x44), 0, 0, 1, *(unsigned char*)((char*)g_IfMngr + 0xA8));
                goto block_70;
            }
            if (g_muWifiInterfaceTask == 0 && fn_8010FF20(*(int*)(p + 0xC4)) != 0) {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, 0x10000, 0, 0, -1);
                fn_800DF68C(*(void**)((char*)g_IfMngr + 0x44), 0, 0, 1, *(unsigned char*)((char*)g_IfMngr + 0xA8));
                *(unsigned char*)(p + 0xBD) = 1;
                goto block_70;
            }
            if (g_muWifiInterfaceTask != 0 && *(unsigned char*)(p + 0xBE) == 0) {
                if (*(int*)(p + 0xC8) <= 0x12C && (*(int*)(p + 0xC8) % 60) == 0) {
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0xA, -1, 0, 0, -1);
                }
                if (--*(int*)(p + 0xC8) <= 0) {
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, 0x10000, 0, 0, -1);
                    fn_800DF68C(*(void**)((char*)g_IfMngr + 0x44), 0, 0, 1, *(unsigned char*)((char*)g_IfMngr + 0xA8));
                    goto block_70;
                }
                goto block_59;
            } else {
block_59:
                *(int*)(p + 0xB4) = *(int*)(d + 0xE8);
                *(int*)(p + 0xB8) = 0x2C3;
            }
        }
        break;
block_60:
        fn_800DCF74(g_IfMngr);
block_61:
        *(int*)(p + 0xB4) = *(int*)(d + 0xEC);
        *(int*)(p + 0xB8) = 0x2CC;
        break;
    case 0x2CC:
        r3 = fn_800DD02C(g_IfMngr, &sp8);
        if (r3 == 0) {
            if (g_muWifiInterfaceTask != 0 && *(unsigned char*)(p + 0xBE) == 0) {
                if (*(int*)(p + 0xC8) <= 0x12C && (*(int*)(p + 0xC8) % 60) == 0) {
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0xA, -1, 0, 0, -1);
                }
                if (--*(int*)(p + 0xC8) <= 0) {
                    fn_800D1ADC(g_muWifiInterfaceTask, 0);
                    *(unsigned char*)(p + 0xBE) = 1;
                }
            }
            goto block_61;
        }
        goto block_25;
block_70:
        *(int*)(p + 0xC8) = 2;
        goto st2e5;
block_wait:
        *(int*)(p + 0xC8) -= 1;
        *(int*)(p + 0xB4) = *(int*)(d + 0xF0);
        *(int*)(p + 0xB8) = 0x2E5;
        break;
    case 0x2E5:
st2e5:
        if (*(int*)(p + 0xC8) > 0) goto block_wait;
        if (g_muWifiInterfaceTask == 0) goto block_87;
        if (*(unsigned char*)(p + 0xBE) != 0) goto block_81;
        fn_800D1ADC(g_muWifiInterfaceTask, 1);
        *(int*)(p + 0xC8) = 0x258;
block_76:
        *(int*)(p + 0xB4) = *(int*)(d + 0xF4);
        *(int*)(p + 0xB8) = 0x2F3;
        break;
    case 0x2F3:
        r3 = (void*)p;
        {
            int tmp = *(int*)((char*)r3 + 0xC8);
            *(int*)((char*)r3 + 0xC8) = tmp - 1;
            if (fn_800D1BC8(g_muWifiInterfaceTask) != 0 || *(int*)(p + 0xC8) <= 0) {
                if (fn_800D1BC8(g_muWifiInterfaceTask) == 0) {
                    OSReport(d + 0x100);
                    fn_800D1ADC(g_muWifiInterfaceTask, 0);
                    *(unsigned char*)(p + 0xBE) = 1;
                    goto block_81;
                }
                goto block_87;
            }
            goto block_76;
        }
block_81:
        *(int*)(p + 0xC8) = 0x258;
block_82:
        *(int*)(p + 0xB4) = *(int*)(d + 0xF8);
        *(int*)(p + 0xB8) = 0x302;
        break;
    case 0x302:
        r3 = (void*)p;
        {
            int tmp2 = *(int*)((char*)r3 + 0xC8);
            *(int*)((char*)r3 + 0xC8) = tmp2 - 1;
            if (fn_800CCF1C(g_muWifiInterfaceTask) != 0 || *(int*)(p + 0xC8) <= 0) {
                if (fn_800CCF1C(g_muWifiInterfaceTask) == 0) {
                    OSReport(d + 0x134);
                }
block_87:
                *(unsigned char*)(p + 0xBC) = 1;
                *(int*)(p + 0xB4) = *(int*)(d + 0xFC);
                *(int*)(p + 0xB8) = 0x310;
                break;
            }
            goto block_82;
        }
        break;
    }
    return *(unsigned char*)(p + 0xBC);
}
