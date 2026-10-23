#include <types.h>
#pragma force_active on

class gfPadSystem {
public:
    char pad[0x35];
    u8 unk35 : 1;
    u8 rest : 7;
};

extern "C" void wpadGameDataCallback__11gfPadSystemFi(int);
extern "C" u32 fn_80224D18(int, int, int, int, void (*)(int));

extern "C" u32 writeGameDataRequest__11gfPadSystemFiiii(gfPadSystem *self, int a, int b, int c, int d) {
    self->unk35 = 0;
    return fn_80224D18(a, b, c, d, wpadGameDataCallback__11gfPadSystemFi) == 0;
}
