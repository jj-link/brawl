#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_3958;
extern "C" int randi__Fl(long);

class Stage {
public:
    void getFighterStartPos(Vec3f* pos, int idx);
    void getFighterReStartPos(Vec3f* pos, int idx);
};

class stMelee : public Stage {
public:
    void getFighterStartPos(Vec3f* pos, int idx);
};

void stMelee::getFighterStartPos(Vec3f* pos, int idx) {
    if ((u32)idx == 30) {
        u32 prev = *(u32*)((char*)this + 0x1cc);
        u32 r;
        do {
            r = randi__Fl(4);
            *(u32*)((char*)this + 0x1cc) = r;
        } while (r == prev);
        Stage::getFighterReStartPos(pos, r);
        pos->y = pos->y + lbl_27_rodata_3958;
    } else {
        Stage::getFighterStartPos(pos, *(int*)((char*)this + 0x1b4 + idx * 4));
    }
}
