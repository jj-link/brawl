#pragma force_active on
// ft_yoshi: getter returning the address of the module-static 4-byte object
// (compiled to "lis r3, lbl_95_bss_344@ha; addi r3, r3, lbl_95_bss_344@l; blr").

struct YoshiUnknown4 {
    unsigned int data;
};

extern "C" YoshiUnknown4 lbl_95_bss_344;

extern "C" YoshiUnknown4 *fn_95_F3D4(void)
{
    return &lbl_95_bss_344;
}
