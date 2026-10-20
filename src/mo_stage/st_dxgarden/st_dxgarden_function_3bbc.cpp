#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad[8];
    u32 bits : 2;
    u32 rest : 30;
} S;

extern "C" void fn_77_3BBC(S *self, int val) {
    self->bits = val;
}
