#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern "C" int fn_802AA280(u32 arg) {
 u32 x = ((u32*)arg)[1];
 arg = ((u32*)arg)[3];
 return ((arg << __cntlzw(arg ^ x)) >> 7) & 0x01000000;
}
