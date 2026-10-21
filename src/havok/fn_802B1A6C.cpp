extern "C" {
extern const float lbl_805A3F38;
extern const float lbl_805A3F3C;
}

#pragma force_active on
extern "C" void fn_802B1A6C(float *arg0)
{
    float one = lbl_805A3F3C;
    float zero = lbl_805A3F38;
    *(float *)((char *)arg0 + 0x2c) = zero;
    *(float *)((char *)arg0 + 0x28) = zero;
    *(float *)((char *)arg0 + 0x24) = zero;
    *(float *)((char *)arg0 + 0x20) = zero;
    *(float *)((char *)arg0 + 0x18) = one;
}
