// Runtime.PPCEABI.H/fn_803F5EF4.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F5EF4.s
// (MSL mbtowc/wctomb pair plus the stdio orientation dispatch tail). Behavior
// recovered from the target disassembly; the wide dispatch reads a callback
// table from the stdou-style FILE descriptor stored through lbl_804942B8 and
// tail-calls its entry 0x20 slot.

extern char lbl_804942B8[];

asm void fn_803F5EF4(void);
asm void fn_803F5EF4(void) {
    nofralloc;
    lis     r6, lbl_804942B8@ha;
    addi    r6, r6, lbl_804942B8@l;
    lwz     r6, 0x38(r6);
    lwz     r12, 0x20(r6);
    mtctr   r12;
    bctr
}

asm int fn_803F5F0C(char* pwc, const char* s, int n);
asm int fn_803F5F0C(char* pwc, const char* s, int n) {
    nofralloc;
    cmpwi   r4, 0x0;
    bne     L_803F5F1C;
    li      r3, 0x0;
    blr
L_803F5F1C:
    cmpwi   r5, 0x0;
    bne     L_803F5F2C;
    li      r3, -0x1;
    blr
L_803F5F2C:
    cmpwi   r3, 0x0;
    beq     L_803F5F3C;
    lbz     r0, 0x0(r4);
    sth     r0, 0x0(r3)
L_803F5F3C:
    lbz     r0, 0x0(r4);
    extsb.  r0, r0;
    bne     L_803F5F50;
    li      r3, 0x0;
    blr
L_803F5F50:
    li      r3, 0x1;
    blr
}

asm int fn_803F5F58(char* s, char c);
asm int fn_803F5F58(char* s, char c) {
    nofralloc;
    cmpwi   r3, 0x0;
    bne     L_803F5F68;
    li      r3, 0x0;
    blr
L_803F5F68:
    stb     r4, 0x0(r3);
    li      r3, 0x1;
    blr
}
