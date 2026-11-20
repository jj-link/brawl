#pragma force_active on

struct MtxFlags {
    int flags;
    float _04;
    float _08;
    float _0c;
    float _10;
    float _14;
    float _18;
    float _1c;
    float _20;
    float _24;
    float _28;
    float _2c;
    float _30;
    float _34;
    float _38;
    float _3c;
    float _40;
    float _44;
    float _48;
};

extern const float lbl_805A31F0;
extern const float lbl_805A31F4;
extern const float lbl_805A3200;
extern "C" void fn_801629AC(float*, float, float, float);

extern "C" void fn_80195A14(MtxFlags* a0, const float* a1) {
    if (lbl_805A31F0 == a1[0] && lbl_805A31F0 == a1[1] && lbl_805A31F0 == a1[2]) {
        int v = 0x20;
        if (a0->flags & 0x40) {
            v |= 0x4;
            if (a0->flags & 0x8) {
                v |= 0x2;
            }
        }
        a0->flags = a0->flags | v;
        a0->_1c = lbl_805A31F4;
        a0->_20 = lbl_805A31F0;
        a0->_24 = lbl_805A31F0;
        a0->_2c = lbl_805A31F0;
        a0->_30 = lbl_805A31F4;
        a0->_34 = lbl_805A31F0;
        a0->_3c = lbl_805A31F0;
        a0->_40 = lbl_805A31F0;
        a0->_44 = lbl_805A31F4;
    } else {
        float saved[3];
        float last = a0->_48;
        saved[1] = a0->_38;
        saved[0] = a0->_28;
        saved[2] = last;
        float x, y, z;
        z = a1[2];
        y = a1[1];
        x = a1[0];
        fn_801629AC((float*)((char*)a0 + 0x1c), lbl_805A3200 * x, lbl_805A3200 * y, lbl_805A3200 * z);
        a0->_28 = saved[0];
        a0->_38 = saved[1];
        a0->_48 = saved[2];
        a0->_10 = a1[0];
        a0->_14 = a1[1];
        a0->_18 = a1[2];
        a0->flags = a0->flags & ~0x26;
    }
    a0->flags = a0->flags | 0x80000000;
}
