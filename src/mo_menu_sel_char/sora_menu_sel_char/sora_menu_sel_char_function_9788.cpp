#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <mu/selchar/mu_selchar_player_area.h>
#pragma force_active on

extern "C" {
u8 fn_800D81AC(void*, int, u8*);
u8 fn_10_1278();
void fn_10_1A408(void*);
void fn_10_130E8(void*);
int fn_800CA6D4(void*, int);
void fn_10_17644(void*, int, u8);
}

extern "C" void fn_10_9788(muSelCharTask* self, int slot) {
    u8 local;
    int handSlot;
    muWifiInterfaceTask* wifi = g_muWifiInterfaceTask;
    muSelCharPlayerArea* area = self->m_selCharPlayerAreas[slot];
    int owner;
    int state = ((u8*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r;
            if (state >= 0xc && state < 0x10) r = 1; else r = 0;
            result = 3;
            if (r != 0) result = 2;
        }
    }
    if (result == 2) {
        if (area->_0 == 0 && area->m_playerKind == 2) {
            u8 remote = fn_800D81AC(wifi, slot, &local);
            if (remote != 0xff) {
                u8 own = fn_10_1278();
                if (own == 0xff) own = 4;
                if (remote != own) {
                    muSelCharTask* cursor = self;
                    for (int i = 0; i < *(int*)((u8*)self + 0x648); ++i) {
                        muSelCharHand* hand = cursor->m_selCharPlayerAreas[0]->m_selCharHand;
                        int selected = 0;
                        if (&handSlot != 0)
                            handSlot = *(int*)((u8*)hand + 0xa8);
                        int valid;
                        if ((u32)(hand->m_mode - 5) <= 3) {
                            owner = handSlot;
                            valid = 1;
                        } else {
                            valid = 0;
                        }
                        if (valid != 0 && owner == slot) selected = 1;
                        muSelCharCoin* coin = hand->m_selCharCoin;
                        if (coin != 0 && slot == coin->m_selCharPlayerArea->m_areaIdx)
                            selected = 1;
                        if (selected != 0) fn_10_1A408(hand);
                        cursor = (muSelCharTask*)((u8*)cursor + 4);
                    }
                    fn_10_130E8(area);
                }
            }
        }
        if (*((u8*)self + 0x5c8) != 0 && (int)area->_0 == 1) {
            int value = fn_800CA6D4(wifi, slot);
            if (value != 3 && value != area->m_teamColor)
                fn_10_17644(area, value, area->m_teamSet);
        }
    }
}
