#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern float lbl_27_data_547E0;

class grGimmick {
public:
    void startGimmickSE(u32);
    void startGimmickEffect(u32);
};

class grGimmickMotionPath : public grGimmick {
public:
    void startMove();
};

void grGimmickMotionPath::startMove() {
    float* src = *(float**)((char*)this + 0x164);
    float f = *src;
    *(float*)((char*)this + 0x64) = f;
    float c = lbl_27_data_547E0;
    float g = f * c;
    *(u8*)((char*)this + 0x14c) = 1;
    *(float*)((char*)this + 0x158) = g;
    *(float*)((char*)this + 0x15c) = g;
    if (*(int*)((char*)this + 0xa8) != 0) {
        for (int i = 0; i < 5; i++) {
            startGimmickSE(i + 3);
        }
    }
    if (*(int*)((char*)this + 0xb0) != 0) {
        for (int i = 0; i < 5; i++) {
            startGimmickEffect(i + 3);
        }
    }
}
