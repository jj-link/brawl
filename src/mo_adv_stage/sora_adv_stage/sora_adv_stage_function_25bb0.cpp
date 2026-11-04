#include <gm/gm_global.h>
#include <gr/gr_gimmick.h>

#pragma force_active on

struct AdvDataView {
    unsigned char pad0[0x5FD];
    unsigned char current;
    unsigned char pad1[0x4916 - 0x5FE];
    unsigned char previous;
};

struct MotionPathInfoWords {
    unsigned int words[9];
};

extern MotionPathInfoWords lbl_40_rodata_3B8;
extern const char lbl_40_data_72E8[];
extern const char lbl_40_data_72F8[];

extern "C" void fn_40_25BB0(grGimmick* self, int arg1)
{
    int found = (int)self->getNodeIndex(0, lbl_40_data_72E8);
    *(int*)((char*)self + 0x160) = found;
    *(int*)((char*)self + 0x164) = 2;

    if (found != 0) {
        self->makeCalcuCallback(3, (Heaps::HeapType)0xF);
        *(int*)((char*)*(void**)((char*)self + 0xD4) + 0x100) =
            *(int*)((char*)self + 0x160);
        *(int*)((char*)*(void**)((char*)self + 0xD4) + 0x104) = 6;
    } else {
        self->makeCalcuCallback(2, (Heaps::HeapType)0xF);
    }

    self->setCalcuCallbackRoot(3);
    *(int*)((char*)*(void**)((char*)self + 0xD4) + 0x80) =
        *(int*)((char*)self + 0x15C);
    *(int*)((char*)*(void**)((char*)self + 0xD4) + 0x84) = 3;

    AdvDataView* data = (AdvDataView*)g_GameGlobal->m_advData;
    int current = data->current;
    int value = current - data->previous;
    int lower = current - 5;
    if (value < lower)
        value = lower;
    if (value < 0)
        value = 0;
    if (value > 14)
        value = 14;

    *(float*)((char*)*(float**)((char*)self + 0x154)) =
        *(float*)((char*)*(float**)((char*)self + 0x154) +
                  ((value << 2) & 0x3FC) + 0xAC);

    MotionPathInfoWords info = lbl_40_rodata_3B8;
    *(int*)&info = arg1;
    *(float**)((char*)&info + 4) = *(float**)((char*)self + 0x154);
    self->createAttachMotionPath(
        (grGimmickMotionPathInfo*)&info, 0, lbl_40_data_72F8);
}
