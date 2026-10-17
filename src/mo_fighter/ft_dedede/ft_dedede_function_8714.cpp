// fn_117_8714 initializes the command-resource block that fn_117_70 (the
// module's fighter-build function) keeps at its work-area argument. fn_117_70
// is the unit's only caller: its bl at .text+0x910 (48 00 7E 05) resolves to
// 0x910 + 0x7E04 = 0x8714, and no relocation in any ft_dedede.rel import
// stream points at 0x8714 (evidence/rel_decode_8714.py; the m27 anchors
// 0xE20C->0x135468, 0xE274->0x135EB4, 0xE27C->0x13C428 re-verify the decode).
//
// The original words at .text[0x8714,0x8790) are 9421FFE0 7C0802A6 90010024
// 39610020 4801B7D5 7C7D1B78 7C9E2378 7CBF2B78 38800007 38A00000 4801B7BD
// 387D0098 38800000 4801B7B1 387D00F4 7FC4F378 7FA5EB78 38DD0098 7FE7FB78
// 3D000000 39080000 3D200000 39290000 4801B789 7FA3EB78 39610020 4801B77D
// 80010024 7C0803A6 38210020 4E800020, i.e. stwu r1,-0x20(r1); mflr r0;
// stw r0,0x24(r1); addi r11,r1,0x20; bl _savegpr_29; mr r29,r3; mr r30,r4;
// mr r31,r5; li r4,0x7; li r5,0x0; bl fn_27_19824C; addi r3,r29,0x98;
// li r4,0x0; bl fn_27_198148; addi r3,r29,0xF4; mr r4,r30; mr r5,r29;
// addi r6,r29,0x98; mr r7,r31; lis r8,lbl_117_bss_2EC@ha;
// addi r8,r8,lbl_117_bss_2EC@l; lis r9,lbl_117_bss_31C@ha;
// addi r9,r9,lbl_117_bss_31C@l; bl fn_27_B7E20; mr r3,r29;
// addi r11,r1,0x20; bl _restgpr_29; lwz r0,0x24(r1); mtlr r0;
// addi r1,r1,0x20; blr.
//
// Relocations hitting the window (evidence/rel_decode_8714.py):
//   .text+0x10 R_PPC_REL24 _savegpr_29   (m0 stream, symsec 4, 0x803F1328)
//   .text+0x28 R_PPC_REL24 fn_27_19824C  (m27 stream, symsec 1, +0x19824C)
//   .text+0x34 R_PPC_REL24 fn_27_198148  (m27 stream, symsec 1, +0x198148)
//   .text+0x4E R_PPC_ADDR16_HA lbl_117_bss_2EC (m117 stream, symsec 6, +0x2EC)
//   .text+0x52 R_PPC_ADDR16_LO lbl_117_bss_2EC (m117 stream, symsec 6, +0x2EC)
//   .text+0x56 R_PPC_ADDR16_HA lbl_117_bss_31C (m117 stream, symsec 6, +0x31C)
//   .text+0x5A R_PPC_ADDR16_LO lbl_117_bss_31C (m117 stream, symsec 6, +0x31C)
//   .text+0x5C R_PPC_REL24 fn_27_B7E20   (m27 stream, symsec 1, +0xB7E20)
//   .text+0x68 R_PPC_REL24 _restgpr_29   (m0 stream, symsec 4, 0x803F1374)
//
// Behaviour: the block's primary calculator (+0x00) is initialized through
// fn_27_19824C, the sora_melee soArrayVectorCalculator postInitialize path
// (its body stores the lbl_27_data_3A7E8 interface pair at +0x00/+0x04, packs
// the kind into the +0x08 bitfield and calls
// postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell),
// here with kind 7 and a trailing zero argument the callee does not read.
// The second calculator area (+0x98) is cleared through fn_27_198148 (which
// re-arms the lbl_27_data_3BA20 interface pair; its second parameter is also
// unread). The mediator block at +0xF4 is then constructed through
// fn_27_B7E20, which receives the caller's context pointer, this owning
// block, the +0x98 calculator, the int argument, and the module's singleton
// objects lbl_117_bss_2EC (0x14 bytes) and lbl_117_bss_31C (0xC bytes, the
// Waddledee pick-transactor storage recorded by the 121E4 unit); B7E20 stores
// those two singletons into the mediator at +0x44 and +0x48. The block
// pointer is returned unchanged.

// TU-local view of the command-resource block covering exactly the regions
// this unit initializes. The block continues past +0x14F in the original
// (fn_27_B7E20's stores into the mediator reach +0x68), so the extent beyond
// the observed stores is not pinned by this unit.
struct DededeCommandResources {
    unsigned char calcArea[0x98]; // +0x00: soArrayVectorCalculator area initialized through fn_27_19824C (its header words land at +0x00..0x0C)
    unsigned char workCalc[0x5C]; // +0x98: second calculator area cleared through fn_27_198148 and handed to the mediator initializer
    unsigned char mediator[0x6C]; // +0xF4: mediator block constructed through fn_27_B7E20
};

extern "C" {
void fn_27_19824C(void* calculator, int kind, int param);
void fn_27_198148(void* calculator, int param);
void fn_27_B7E20(void* mediator, void* context, void* owner, void* workCalc,
                 int index, void* singletons, void* pickTransactor);

extern unsigned char lbl_117_bss_2EC[0x14];
extern unsigned char lbl_117_bss_31C[0xC];
}

extern "C" DededeCommandResources* fn_117_8714(DededeCommandResources* resources,
                                               void* context, int index) {
    fn_27_19824C(resources, 7, 0);
    fn_27_198148(&resources->workCalc, 0);
    fn_27_B7E20(&resources->mediator, context, resources, &resources->workCalc,
                index, lbl_117_bss_2EC, lbl_117_bss_31C);
    return resources;
}
