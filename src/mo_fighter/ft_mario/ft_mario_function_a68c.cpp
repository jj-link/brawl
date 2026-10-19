#pragma force_active on
extern "C" const float lbl_91_rodata_8;

class PositionSource {
public:
    virtual void reserved0();
    virtual void reserved1();
    virtual unsigned long long getPosition();
};

union PositionResult {
    unsigned long long value;
    struct {
        float x, y;
    } position;
};

extern "C" void fn_91_A68C(float* out, PositionSource* source) {
    PositionResult result;
    result.value = source->getPosition();
    out[0] = result.position.x;
    out[1] = result.position.y;
    out[2] = lbl_91_rodata_8;
}
