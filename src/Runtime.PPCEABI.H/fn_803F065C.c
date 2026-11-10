#pragma force_active on
typedef struct {
    signed char gpr;
    signed char fpr;
    char *overflow_arg_area;
    char *reg_save_area;
} va_list_struct;

int __va_arg(va_list_struct *ap, int kind)
{
    signed char *save;
    int gpr, needed, size, gpr_inc, ld, reg_off, align, result, mask;

    gpr = ap->gpr;
    save = &ap->gpr;
    needed = 8;
    size = 4;
    gpr_inc = 1;
    ld = 0;
    reg_off = 0;
    align = 4;

    if (kind == 3) {
        save = &ap->fpr;
        gpr = ap->fpr;
        size = 8;
        reg_off = 0x20;
        align = 8;
    }
    if (kind == 2) {
        size = 8;
        needed = 7;
        if ((gpr & 1) != 0)
            ld = 1;
        gpr_inc = 2;
    }
    if (gpr < needed) {
        gpr += ld;
        result = gpr * align + ((int)ap->reg_save_area + reg_off);
        *save = gpr + gpr_inc;
    } else {
        *save = 8;
        mask = ~(size - 1);
        result = mask & (size + (int)ap->overflow_arg_area - 1);
        ap->overflow_arg_area = (char *)(result + size);
    }
    if (kind == 0)
        result = *(int *)result;
    return result;
}
