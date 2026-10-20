#include <types.h>
#pragma force_active on

struct _fn_27_AAA88_struct {
    int _0;
    int _4;
    unsigned int a : 15;
    unsigned int b : 1;
};

extern "C" unsigned int fn_27_AAA88(_fn_27_AAA88_struct* p) {
    return p->b;
}
