#include <types.h>
#pragma force_active on

extern "C" {

struct fn27Obj {
    int _0;
    int _4;
    unsigned int _8 : 18;
    unsigned int flag : 1;
};

int fn_27_FED58(fn27Obj* p) {
    return p->flag;
}

}
