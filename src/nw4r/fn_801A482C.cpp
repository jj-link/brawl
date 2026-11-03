#include <nw4r/math/math_types.h>
#pragma force_active on

using nw4r::math::MTX33;
using nw4r::math::MTX34;

extern "C" void fn_801A3A44(MTX34*, MTX33*, MTX34*, unsigned int*, unsigned int, const MTX34*, unsigned int*, MTX34*);
extern "C" void fn_801EC284(const MTX34*, const MTX34*, MTX34*, unsigned int);
extern "C" void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
extern "C" void fn_801A4760(const MTX34*, const MTX34*, MTX33*);
extern "C" void fn_80162B0C(MTX34*, const MTX33*);
extern "C" void fn_801EC514(const MTX34*, MTX34*);
extern "C" void fn_80162798(MTX33*, const MTX34*);
extern "C" void fn_801627CC(MTX33*, const MTX34*);
extern "C" void fn_801D7748(void*, unsigned int);
extern const float lbl_805A3340;

extern "C" void fn_801A482C(MTX34* arg0, MTX33* arg1, MTX34* arg2, unsigned int* arg3, unsigned int count, const MTX34* arg5, const MTX34* arg6, const unsigned int* arg7, MTX34* arg8) {
    if (arg6 == 0) {
        unsigned int flags = *arg7;
        fn_801A3A44(arg0, arg1, arg2, arg3, count, arg5, &flags, arg8);
        return;
    }
    if (count != 0) {
        unsigned int size33;
        MTX33* p33;
        MTX34* p34;
        MTX34* p34b;
        unsigned int size34 = (count * 0x30 + 0x1f) & ~0x1f;
        size33 = (count * 0x24 + 0x1f) & ~0x1f;
        if (count > 1) {
            fn_801EC284(arg5, arg2, arg0, count);
        } else {
            fn_801EC1B8(arg5, arg2, arg0);
        }
        if (arg1 != 0) {
            p33 = arg1;
            p34 = arg8;
            p34b = arg8;
            for (unsigned int i = 0; i < count; ++i) {
                if (*arg3 & 0x20000000) {
                    fn_801A4760(arg6, arg2, p33);
                    if (arg8 != 0) {
                        fn_80162B0C(p34, p33);
                        p34->_03 = p34->_13 = p34->_23 = lbl_805A3340;
                    }
                } else {
                    MTX34 temp;
                    fn_801EC1B8(arg6, arg2, &temp);
                    if (arg8 != 0) {
                        fn_801EC514(&temp, p34);
                        fn_80162798(p33, p34b);
                    } else {
                        fn_801627CC(p33, &temp);
                    }
                }
                ++p33;
                ++arg3;
                ++arg2;
                ++p34;
                ++p34b;
            }
        }
        fn_801D7748(arg0, size34);
        if (arg1 != 0) {
            fn_801D7748(arg1, size33);
            if (arg8 != 0) {
                fn_801D7748(arg8, size34);
            }
        }
    }
}
