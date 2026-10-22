#pragma force_active on

typedef unsigned char u8;

extern "C" void fn_8009CF04(u8* p, const float* s) {
    float out3, out2, out1, out0;
    float x = *(float*)(p + 0xA4) + *(float*)(p + 0x168);
    float y = *(float*)(p + 0xA8) + *(float*)(p + 0x16C);
    float v3, v2, v1, v0;

    v0 = s[0];
    v1 = s[1];
    v2 = s[2];
    v3 = s[3];

    out0 = v0 + x;
    out1 = v1 + x;
    out2 = v2 + y;
    out3 = v3 + y;

    *(float*)(p + 0x138) = v0;
    *(float*)(p + 0x13C) = v1;
    *(float*)(p + 0x140) = v2;
    *(float*)(p + 0x144) = v3;
    *(float*)(p + 0x158) = out0;
    *(float*)(p + 0x15C) = out1;
    *(float*)(p + 0x160) = out2;
    *(float*)(p + 0x164) = out3;
}
