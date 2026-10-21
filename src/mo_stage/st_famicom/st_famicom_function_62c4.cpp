#pragma force_active on

struct __StFamicom2 {
    int _0x0;
    int _0x4;
    union {
        struct {
            int : 4;
            signed int value : 2;
            int : 26;
        } _f;
    } _0x8;
};

extern "C" int fn_68_62C4(__StFamicom2 *self) {
    return self->_0x8._f.value;
}
