#include <types.h>
#include <ip/ip_switch.h>
#include <ft/ft_manager.h>
#include <if/if_mngr.h>
#include <snd/snd_system.h>
#pragma force_active on

struct SlotTask_base { char pad[0x3c]; };
class SlotTask : public SlotTask_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
};

extern "C" {
extern f32 lbl_27_rodata_4028;
extern s32 lbl_27_data_4F050[];
void fn_27_111B14(void* owner, s32 arg);
void fn_800DCCBC(void* ifMngr, u8 a, u8 b);
s32 getEntryId__9ftManagerFi(void* mgr, s32 playerNo);
s32 isValidEntryId__9ftManagerFi(void* mgr, s32 entryId);
void* getOwner__9ftManagerFi(void* mgr, s32 entryId);
s32 getStockCount__7ftOwnerFv(void* owner);
}

extern "C" void fn_27_24D9D8(char* self) {
    char* e;
    s32* data = lbl_27_data_4F050;
    if (*(u8*)(self + 0x248) != 0) {
        switch (*(u8*)(self + 0x76)) {
        case 0:
            break;
        default:
            return;
        }
        {
            switch (*(s32*)(self + 0x250)) {
            case 0:
                *(s32*)(self + 0x24C) = data[0x1AC / 4];
                *(s32*)(self + 0x250) = 0xC64;
                /* fallthrough */
            case 0xC64: {
                char* base = *(char**)(self + 0x44);
                u32 kind = ((u32)*(u8*)(base + 0x8) >> 2) & 0x3F;
                switch (kind) {
                case 0:
                case 1:
                case 14:
                case 23:
                case 24:
                case 28:
                case 33: {
                    u8 flag = 0;
                    if ((((u32)*(u8*)(base + 0x9) >> 5) & 7) == 1 && *(u8*)(base + 0x13) == 1) {
                        flag = 1;
                    }
                    *(u8*)(self + 0x248) = flag;
                    break;
                }
                default:
                    *(u8*)(self + 0x248) = 0;
                    break;
                }
                *(s32*)(self + 0x24C) = data[0x1B0 / 4];
                *(s32*)(self + 0x250) = 0xC74;
                return;
            }
            case 0xC74:
            case 0xCEF: {
                f32 zero = lbl_27_rodata_4028;
                s32 off;
                char* objp = self;
                s32 i = 0;
                off = 0;
                for (; i < 4; i++, off += 0x5C, objp += 4) {
                    e = *(char**)(self + 0x44) + off;
                    if (*(u8*)(e + 0x99) == 0) {
                        if (*(u8*)(e + 0x9F) != 0) {
                            char* fighter = *(char**)(self + 0xCC) + *(u8*)(e + 0x9B) * 0x2AC;
                            if (*(s8*)(fighter + 0x2E) == 0) {
                                ipPadStatus pad;
                                ipSwitch::getInstance()->getPadStatus(i, pad);
                                if (pad.m_button & 0x10) {
                                    s32 team = *(u8*)(e + 0xA3);
                                    s32 best = 1;
                                    char* bestPtr = 0;
                                    s32 bestJ;
                                    for (s32 j = 0; j < 4; j++) {
                                        if (j != i) {
                                            char* p = *(char**)(self + 0x44) + j * 0x5C;
                                            char* q = p + 0x98;
                                            if (*(u8*)(p + 0xA3) == team) {
                                                char* f = *(char**)(self + 0xCC) + *(u8*)(q + 3) * 0x2AC;
                                                s8 v = *(s8*)(f + 0x2E);
                                                if (best < v) {
                                                    best = v;
                                                    bestPtr = q;
                                                    bestJ = j;
                                                }
                                            }
                                        }
                                    }
                                    if (bestPtr != 0) {
                                        g_sndSystem->playSE((SndID)0x1FD1, *(s32*)(self + 0xAC), 0, 0, -1);
                                        s32 entry = getEntryId__9ftManagerFi(g_ftManager, bestJ);
                                        if (isValidEntryId__9ftManagerFi(g_ftManager, entry) != 0) {
                                            void* owner1 = getOwner__9ftManagerFi(g_ftManager, entry);
                                            s32 stocks = getStockCount__7ftOwnerFv(owner1);
                                            if (stocks > 1) {
                                                s32 entry2 = getEntryId__9ftManagerFi(g_ftManager, i);
                                                if (isValidEntryId__9ftManagerFi(g_ftManager, entry2) != 0) {
                                                    void* owner2 = getOwner__9ftManagerFi(g_ftManager, entry2);
                                                    fn_27_111B14(owner2, 1);
                                                    fn_27_111B14(owner1, stocks - 1);
                                                    *(f32*)(*(char**)(objp + 0x58) + 0x48) = zero;
                                                    ((SlotTask*)*(char**)(objp + 0x58))->slot23();
                                                    if (g_IfMngr != 0) {
                                                        fn_800DCCBC(g_IfMngr, *(u8*)(bestPtr + 2), *(u8*)(e + 0x9A));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                *(s32*)(self + 0x24C) = data[0x1B4 / 4];
                *(s32*)(self + 0x250) = 0xCEF;
                break;
            }
            }
        }
    }
}