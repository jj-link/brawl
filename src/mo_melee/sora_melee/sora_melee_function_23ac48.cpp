#include <types.h>
#pragma force_active on

struct Unk46 {
    u8 pad[0x46];
    u8 flag;
};

extern "C" int fn_27_23AC48(Unk46* p) {
    if (p->flag == 1) {
        return 0;
    }
    p->flag = 1;
    return 1;
}
