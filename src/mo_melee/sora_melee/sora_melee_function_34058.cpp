#pragma force_active on
typedef unsigned long long u64;

extern "C" const float lbl_27_rodata_450;

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual int test();
    unsigned char padding[0x18];
    float x;
    float y;
};

union Pair {
    struct {
        float x;
        float y;
    } f;
    u64 bits;
};

extern "C" u64 fn_27_34058(Object* self) {
    if (self->test() == 0) {
        Pair value;
        value.f.x = lbl_27_rodata_450;
        value.f.y = lbl_27_rodata_450;
        return value.bits;
    }
    return *(u64*)&self->x;
}
