#include <types.h>
#pragma force_active on
struct InitState {
 int x0, x4;
 u16 x8, xA;
 u8 xC, xD;
 u16 xE;
};
extern "C" void fn_801BAA94(InitState* out, int val) {
 out->x4 = 0;
 out->xC = 1;
 out->x0 = val;
 out->x8 = 0x8000;
 out->x4 = 0;
 out->xC = 1;
 out->xE = 0x8000;
 out->xA = 0;
}
