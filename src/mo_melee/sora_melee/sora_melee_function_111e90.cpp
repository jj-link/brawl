#include <types.h>
#pragma force_active on

struct Work {
    u8 pad[0x1c];
    u8 x : 5;
    u8 flag : 1;
    u8 rest : 2;
};

extern "C" {
    bool fn_27_111E90(Work** self) {
        return (*self)->flag;
    }
}
