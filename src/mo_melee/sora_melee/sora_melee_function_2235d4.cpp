#pragma force_active on
extern "C" const float lbl_27_rodata_3430;

class Stage {
public:
    float getKirifudaAngle(unsigned long idx);
};

float Stage::getKirifudaAngle(unsigned long idx) {
    char* p = *(char**)((char*)this + 0x98);
    if (p == 0) {
        return lbl_27_rodata_3430;
    }
    if (idx >= 7) {
        return lbl_27_rodata_3430;
    }
    switch (idx) {
    case 2:
        return *(float*)(p + 0xA8);
    default:
        return lbl_27_rodata_3430;
    }
}
