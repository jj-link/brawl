#include <types.h>
#pragma force_active on
extern "C" {
struct PadStatusLocal { int words[16]; };
struct SoraMenuMain { char pad[0x110]; int unk110; char pad2[0x94]; int unk1A8; char pad3[4]; int unk1B0; char pad4[0xC]; int unk1C0; int unk1C4; };
void fn_800B9F90(PadStatusLocal*, void*, int);
void fn_2_3B850(void*, int, int);
void fn_2_3C784(SoraMenuMain* self) {
 PadStatusLocal local;
 fn_800B9F90(&local, (void*)((char*)self + 0x100), 0);
 int flags_110 = self->unk110;
 int val_b0 = self->unk1B0;
 int quotient = val_b0 / 3;
 int val_c4 = self->unk1C4;
 int flags_a8 = self->unk1A8;
 int col = val_b0 % 3;
 int rows = (val_c4 + 5) / 6;
 int row = self->unk1C0;
 if (flags_a8 & 8) {
  int x = row - 1;
  row = x & ((-x & ~x) >> 31);
 } else if (flags_a8 & 0x10) {
  row = (row + 1 < rows - 1) ? row + 1 : rows - 1;
 } else if (flags_110 & 1) {
  if (col > 0) col--;
  else if (row > 0) { col = 2; row--; }
 } else if (flags_110 & 2) {
  if (col < 2) col++;
  else if (row < rows - 1) { col = 0; row++; }
 } else if (flags_110 & 8) {
  quotient = (quotient - 1) & ((-(quotient - 1) & ~(quotient - 1)) >> 31);
 } else if (flags_110 & 4) {
  int t = quotient + 1; quotient = 1; if (t < 1) quotient = t;
 }
 fn_2_3B850(self, col + 3 * quotient, row);
}
}