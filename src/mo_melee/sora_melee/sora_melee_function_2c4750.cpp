#include <types.h>
#pragma force_active on

struct muMenu {
    char pad0[0x44];
    u8 unk44;
    u8 unk45;
    char pad46[6];
    void* unk4C;
    void* unk50;
    s32 unk54;
    char pad58[0x610];
    void* unk668;
    void* unk66C;
    void* unk670;
    void* unk674;
    void* unk678;
    void* unk67C;
    char pad680[4];
    void* unk684;
    void* unk688;
    char pad68C[4];
    void* unk690;
    void* unk694;
    void* unk698;
    void* unk69C;
    void* unk6A0;
    char pad6A4[0x1A878];
    void* unk1AF1C;
    void* unk1AF20;
    char pad1AF24[0xF0];
    void* unk1B014;
};

extern "C" {
void loadMenuSound__6muMenuFv(void);
int isLoadFinishMenuSound__6muMenuFv(void);
void* fn_800AD954(void*);
void* fn_80015E34(void*, s32, s32, s32, s32*, u16);
void* fn_80015DB4(void*, s32, s32, s32, u16);
void fn_8005EFF4(void*, void*, void*, s32, s32);
void* fn_800B03F0(void*, s32);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void setMsgData__5MuMsgFPv(void*, void*);
extern void* g_GameGlobal;
extern void* g_ecMgr;
extern char lbl_27_data_7B298[];
}

extern "C" s32 fn_27_2C4750(muMenu* arg0) {
    char* base = lbl_27_data_7B298;
    s32 sp8;
    s32 var_r6;
    void* var_r29;
    void* temp;
    void* temp_r3;

    while (arg0->unk45 != 0) {
        switch (arg0->unk45) {
        case 1:
            temp = fn_800AD954(arg0->unk6A0);
            if (temp != NULL) {
                if (arg0->unk44 == 1) {
                    loadMenuSound__6muMenuFv();
                    arg0->unk45 += 1;
                } else {
                    arg0->unk45 += 2;
                }
            } else {
                return 0;
            }
            break;
        case 2:
            if (isLoadFinishMenuSound__6muMenuFv() != 0) {
                arg0->unk45 += 1;
            } else {
                return 0;
            }
            break;
        case 3:
            temp = fn_80015E34(arg0->unk1B014, 0, 1, 0x28, &sp8, 0xFFFE);
            arg0->unk50 = temp;
            fn_8005EFF4(g_ecMgr, base + 0xB8, temp, sp8, 0x2B);
            if (arg0->unk54 == 0x134) {
                var_r29 = base + 0xC8;
                var_r6 = 0x14;
            } else {
                var_r6 = 0x46;
                var_r29 = base + 0xD0;
            }
            temp = fn_80015E34(arg0->unk1B014, 0, 1, var_r6, &sp8, 0xFFFE);
            arg0->unk4C = temp;
            fn_8005EFF4(g_ecMgr, var_r29, temp, sp8, 0x2B);
            arg0->unk668 = fn_800B03F0(arg0->unk1B014, -((!((((u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal))[0x28] >> 7) & 1)) & 1) + 0xB);
            arg0->unk66C = fn_800B03F0(arg0->unk1B014, 0x3C);
            arg0->unk670 = fn_800B03F0(arg0->unk1B014, 0x1E);
            arg0->unk674 = fn_800B03F0(arg0->unk1B014, 0x32);
            arg0->unk678 = fn_800B03F0(arg0->unk1B014, 0x64);
            arg0->unk67C = fn_800B03F0(arg0->unk1B014, 0x8C);
            arg0->unk1AF1C = fn_800B03F0(arg0->unk1B014, 0x82);
            arg0->unk1AF20 = fn_80015DB4(arg0->unk1B014, 0, 1, 0x5A, 0xFFFE);
            temp_r3 = fn_80015DB4(arg0->unk1B014, 0, 1, 0x78, 0xFFFE);
            arg0->unk694 = temp_r3;
            setMsgData__5MuMsgFPv(arg0->unk684, temp_r3);
            temp_r3 = fn_80015DB4(arg0->unk1B014, 0, 1, 0x6E, 0xFFFE);
            arg0->unk698 = temp_r3;
            setMsgData__5MuMsgFPv(arg0->unk688, temp_r3);
            temp_r3 = fn_80015DB4(arg0->unk1B014, 0, 1, 0x50, 0xFFFE);
            arg0->unk69C = temp_r3;
            setMsgData__5MuMsgFPv(arg0->unk690, temp_r3);
            arg0->unk45 += 1;
            /* fallthrough */
        default:
            arg0->unk45 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
