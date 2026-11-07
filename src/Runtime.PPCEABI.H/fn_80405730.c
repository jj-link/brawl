#pragma force_active on
#define PASTE(x, y) x##y
#define ASMKEY PASTE(__as, m)

extern unsigned char gTRKCPUState[];
extern unsigned char _db_stack_addr[];
void TRKSaveExtended1Block(void);
int InitMetroTRKCommTable(int);
void TRK_main(void);

ASMKEY void InitMetroTRK_BBA(void) {
    nofralloc
    subi r1, r1, 4
    stw r3, 0x0(r1)
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    stmw r0, 0x0(r3)
    lwz r4, 0x0(r1)
    addi r1, r1, 4
    stw r1, 0x4(r3)
    stw r4, 0xc(r3)
    mflr r4
    stw r4, 0x84(r3)
    stw r4, 0x80(r3)
    mfcr r4
    stw r4, 0x88(r3)
    mfmsr r4
    ori r3, r4, 0x8000
    mtmsr r3
    mtsrr1 r4
    bl TRKSaveExtended1Block
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    lmw r0, 0x0(r3)
    li r0, 0
    mtspr IABR, r0
    mtspr DABR, r0
    lis r1, _db_stack_addr@h
    ori r1, r1, _db_stack_addr@l
    li r3, 2
    bl InitMetroTRKCommTable
    cmpwi r3, 1
    bne done
    lwz r4, 0x84(r3)
    mtlr r4
    lmw r0, 0x0(r3)
    blr
done:
    b TRK_main
    blr
}