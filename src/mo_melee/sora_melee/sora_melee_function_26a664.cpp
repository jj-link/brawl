#pragma force_active on

#include <types.h>
#include <gr/gr_gimmick.h>

struct SimpleSoundData {
    u32 id;
    u16 repeatFrame;
};

extern "C" grVisibleProduction* fn_27_271170(grGimmick* owner, const SimpleSoundData* data);

extern "C" void createSoundEffectVisibleProductionForExcel__9grGimmickFUlUlUl(
    grGimmick* owner, const SimpleSoundData* data, const u32* index, grVisibleProduction** outputs) {
    if (data->id != 0xFFFFFFFFUL) {
        outputs[*index] = fn_27_271170(owner, data);
    }
}
