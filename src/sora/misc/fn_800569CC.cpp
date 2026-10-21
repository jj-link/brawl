#include <types.h>
#pragma force_active on

extern "C" {
void fn_80056B70(void);
void fn_80057158(void);
void fn_80057C64(void);
void fn_80057EAC(void);

void fn_800569CC(void) {
    fn_80056B70();
    fn_80057C64();
    fn_80057158();
    fn_80057EAC();
}
}
