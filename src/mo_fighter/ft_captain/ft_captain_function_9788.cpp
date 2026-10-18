#pragma force_active on
extern const float lbl_100_rodata_8;

struct Pair {
    float x;
    float y;
};

class Result {
public:
    virtual void f0();
    virtual void f1();
    virtual Pair get();
};

extern "C" void fn_100_9788(float* out, Result* result) {
    Pair value = result->get();
    out[0] = value.x;
    out[1] = value.y;
    out[2] = lbl_100_rodata_8;
}
