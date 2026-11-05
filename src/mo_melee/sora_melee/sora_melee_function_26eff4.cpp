#include <types.h>
#pragma force_active on

extern const double lbl_27_rodata_43B8;

class grGimmickMotionPath {
public:
    bool isEndFrame();
private:
    char pad0[0x150];
    float f150;
    char pad154[4];
    float f158;
    char pad15c[4];
    unsigned int u160;
};

bool grGimmickMotionPath::isEndFrame() {
    return this->f150 + this->f158 >= (float)this->u160;
}
