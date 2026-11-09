#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/OS/OSHardware.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
extern __typeof__(MI_HW_REGS[0])* __memReg;
extern u8 fn_801EEF74(void);
extern void fn_801EF0E0(void);
extern void __GXInitRevisionBits(void);
extern void fn_801D50A0(void);
extern void fn_801F0E10(void);
static u32 readCounter(void) {
 u32 hi, lo, old;
 hi = __memReg[39];
 do {
  old = hi;
  lo = __memReg[40];
  hi = __memReg[39];
 } while (hi != old);
 return (hi << 16) | lo;
}
static void delay(s64 ticks) {
 s64 start = OSGetTime();
 while (OSGetTime() - start <= ticks) {}
}
void GXAbortFrame(void) {
 u32 current, old;
 if (__GXData->BYTE_0x5FA && fn_801EEF74()) {
  current = readCounter();
  do {
   delay(8);
   old = current;
   current = readCounter();
  } while (current != old);
 }
 PI_HW_REGS[PI_REG_0x18] = 1;
 delay(50);
 PI_HW_REGS[PI_REG_0x18] = 0;
 delay(5);
 if (fn_801EEF74()) {
  fn_801EF0E0();
  __GXInitRevisionBits();
  __GXData->gxDirtyFlags = 0;
  if (__GXData->gxDirtyFlags) fn_801F0E10();
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  WGPIPE.i = 0;
  fn_801D50A0();
 }
}
