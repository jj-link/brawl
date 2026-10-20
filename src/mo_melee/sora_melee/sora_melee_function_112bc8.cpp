#pragma force_active on
struct SomeObj {
    unsigned char pad[0x81c];
    float value;
};

extern "C" float fn_27_112BC8(SomeObj** p) {
    return (*p)->value;
}
