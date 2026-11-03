#include <mu/adv/mu_adv_difficulty.h>
#include <gf/gf_task.h>
#include <types.h>

#pragma force_active on

extern "C" void exit__6gfTaskFv(void* self);
extern const muAdvDifficultyTaskParam lbl_1_rodata_8E0;

extern "C" s32 fn_1_1CAC0(void* self) {
    s32 do_exit = 0;
    s32 ret = 0;

    if (*(muAdvDifficultyTask**)((char*)self + 0x0C) == NULL) {
        muAdvDifficultyTaskParam param = lbl_1_rodata_8E0;
        if (*(void**)((char*)self + 0x10)) {
            param.unk4 = *(u32*)((char*)*(void**)((char*)self + 0x10) + 0x8);
            param.unk8 = *(u32*)((char*)*(void**)((char*)self + 0x10) + 0xC);
        }
        *(muAdvDifficultyTask**)((char*)self + 0x0C) = muAdvDifficultyTask::create(&param);
    }

    switch (((muAdvDifficultyTask*)*(muAdvDifficultyTask**)((char*)self + 0x0C))->m_option) {
        case 1:
            do_exit = 1;
            ret = 1;
            *(u8*)((char*)*(void**)((char*)self + 0x10) + 0x10) = (u8)((muAdvDifficultyTask*)*(muAdvDifficultyTask**)((char*)self + 0x0C))->m_difficulty;
            break;
        case 2:
            do_exit = 1;
            ret = 0;
            break;
    }

    if (do_exit) {
        exit__6gfTaskFv(*(muAdvDifficultyTask**)((char*)self + 0x0C));
        *(muAdvDifficultyTask**)((char*)self + 0x0C) = NULL;
    }

    return ret;
}