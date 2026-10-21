#include <st_crayon/gr_crayon.h>
#pragma force_active on

struct HeihoEntry {
    float x, y, z;
};

extern "C" HeihoEntry lbl_56_data_1158[];
extern "C" void fn_56_46BC(void*);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

void grCrayonYakumonoH::setLinearHeiho(s32 p1, UnkHeihoStruct p2) {
    if (p1 < 9) {
        *(s32*)((char*)this + 0x16c) = 2;
        *(UnkHeihoStruct*)((char*)this + 0x178) = p2;
        *(float*)((char*)this + 0x170) = lbl_56_data_1158[p1].x;
        *(float*)((char*)this + 0x174) = lbl_56_data_1158[p1].y;
    } else {
        *(s32*)((char*)this + 0x16c) = 0;
    }

    fn_56_46BC(this);
    *(int*)((char*)this + 0x1c0) =
        playSE__14snd3DGeneratorF5SndIDiii(
            (char*)this + 0x1b8, 0x1bdd, 0, 0, -1);
}
