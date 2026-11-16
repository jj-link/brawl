#include <gm/gm_global.h>
#include <ft/ft_manager.h>
#pragma force_active on

struct FighterManagerFlags {
    bool flag : 1;
};

struct AdvStageDataView {
    unsigned char pad0[0x5FD];
    unsigned char current;
    unsigned char pad1[0x4916 - 0x5FE];
    unsigned char previous;
};

extern "C" {
int fn_27_233474(void* obj, unsigned long index, unsigned char value);
void fn_40_16DD8();
void* fn_40_173A0();
void fn_40_168A0();
void fn_40_168A8(void* self, unsigned char value);
}

extern "C" void fn_40_7A94(unsigned char* self) {
    fn_40_16DD8();
    void* r30 = fn_40_173A0();
    fn_40_168A0();

    unsigned long count;
    int sum = 0;
    unsigned long i = 0;
    count = *(unsigned long*)(*(unsigned char**)(self + 0xA0) + 0x50);

    while (i < count) {
        AdvStageDataView* adv = (AdvStageDataView*)g_GameGlobal->m_advData;
        unsigned char current = adv->current;
        unsigned char previous = adv->previous;
        int value = current - previous;
        int lower = current - 5;
        if (value < lower) {
            value = lower;
        }
        if (value < 0) {
            value = 0;
        }
        if (value > 14) {
            value = 14;
        }
        sum += fn_27_233474(*(void**)(self + 0xA0), i, (unsigned char)value);
        i += 1;
    }

    unsigned char* p = *(unsigned char**)(self + 0x524);
    if (p != 0 && p[0x604] == 1) {
        fn_40_168A8(r30, (unsigned char)sum);
    }

    if ((unsigned char)sum == 0) {
        p = *(unsigned char**)(self + 0x524);
        if (p != 0) {
            unsigned char t = p[0x604];
            if (t != 1 && t != 2 && t != 3) {
                ((FighterManagerFlags*)((char*)g_ftManager + 0x6C))->flag = false;
            }
        }
    }
}
