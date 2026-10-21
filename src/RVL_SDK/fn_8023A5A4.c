#pragma force_active on

/* Checks whether the byte at +0x64e of the block starting at lbl_80529CF8
 * (read as an unsigned char) equals 5.  The original compiles to
 *   lbz r3, 0x64e(r3); subi r0, r3, 5; cntlzw r0, r0; extrwi r3, r0, 8, 19
 * i.e. a boolean test of (byte - 5) < 256, which the compiler emits for the
 * equality comparison against 5. */

extern unsigned char lbl_80529CF8[];

unsigned char fn_8023A5A4(void) {
    return lbl_80529CF8[0x64e] == 5;
}
