#pragma force_active on
#pragma once

struct __StFamicom {
    int _0x0;
    int _0x4;
    union {
        struct {
            int : 2;
            int state : 2;
            int : 28;
        } _f;
    } _0x8;
};

extern "C" int fn_68_5DEC(__StFamicom *self) {
    return self->_0x8._f.state;
}
