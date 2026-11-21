#include <gm/gm_global.h>

#pragma force_active on

extern "C" {
u8 fn_10_1278();
u8 fn_800D4544(void*);
void fn_800D82E8(void*, u8*, int);
int fn_10_D07C(void*);
int fn_10_D0A0(void*);
extern void* g_muWifiInterfaceTask;
}

struct SelCharState {
    char pad[0x5d0];
    u8 a;
    u8 b;
    char pad2[2];
    int d4;
    int d8;
    int dc;
};

extern "C" void fn_10_1BBC(SelCharState* self) {
        u8 value;
            int max;
    u8* sel = (u8*)g_GameGlobal->m_selCharData;
    u8* rule = (u8*)g_GameGlobal->m_setRule;

    self->a = 0;
    if ((int)((u8*)g_GameGlobal->m_selCharData)[4] == 2) {
        switch (((u8*)g_GameGlobal->m_setRule)[0x18]) {
        case 2:
            self->a = 1;
            break;
        case 1:
            self->b = 1;
            break;
        }
    }

    int state = ((u8*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4)
        result = 1;
    else
        result = 0;

    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 12)
            result = 1;
        else
            result = 0;

        if (result != 0) {
            result = 1;
        } else {
            int r;
            if (state >= 12 && state < 16)
                r = 1;
            else
                r = 0;
            result = 3;
            if (r != 0)
                result = 2;
        }
    }

    if (result == 2) {
        bool ind;
        {
            u8* task = (u8*)g_muWifiInterfaceTask;
            ind = (task[0xfca] >> 5) & 1;
            if (!ind) {
                value = fn_10_1278();
                if (value == 0xff)
                    value = 4;
                u8 current = fn_800D4544(task);
                ind = current == value;
            }
        }

        if (!ind && sel[6] == 0) {
            u8 buf[4];
            fn_800D82E8(g_muWifiInterfaceTask, buf, 1);
            if ((int)((u8*)g_GameGlobal->m_selCharData)[4] == 0x12)
                self->d4 = 0;
            else
                self->d4 = (buf[0] >> 6) & 3;

            int min;
            max = fn_10_D07C(self);
            min = fn_10_D0A0(self);
            if (buf[2] > min)
                min = buf[2];
            if (min < max)
                max = min;
            self->d8 = max;
            self->dc = buf[3];
            return;
        }
    }

    self->d4 = rule[2];
    self->d8 = rule[3];
    if ((int)((u8*)g_GameGlobal->m_selCharData)[4] == 4)
        self->dc = (sel[0x2e] >> 2) & 7;
    else
        self->dc = rule[4];
}
