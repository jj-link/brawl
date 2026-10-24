#pragma force_active on
typedef unsigned short u16;

extern u16 lbl_804F9EE0[];

void fn_80225454(u16 *p)
{
    u16 *q = lbl_804F9EE0;
    int i;

    for (i = 0; i < 16; i++) {
        if ((*q = *p) == 0)
            break;
        p++;
        q++;
    }

    lbl_804F9EE0[16] = 0;
}
