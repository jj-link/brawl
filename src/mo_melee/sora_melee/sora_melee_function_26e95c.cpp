#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" float fixedPosition__9grGimmickFf(grGimmick* gimmick, float value);

extern "C" void fn_27_26E95C(grGimmick* gimmick) {
    fixedPosition__9grGimmickFf(gimmick, *(float*)((char*)gimmick + 0x15c));
}