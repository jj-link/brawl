#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_120_rodata_8;
void fn_120_BDBC(Vec2f* dst, const Vec2f* src);
}

extern "C" void fn_120_BD84(char* arg0) {
    Vec2f tmp(lbl_120_rodata_8, lbl_120_rodata_8);
    fn_120_BDBC((Vec2f*)(arg0 + 8), &tmp);
}
