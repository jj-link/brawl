#pragma force_active on

typedef struct Obj {
    unsigned char pad[0x680];
    unsigned char bytes[18];
    unsigned short field692;
    unsigned short field694;
    unsigned char pad696[2];
    unsigned char pad698[4];
    unsigned char *ptr;
} Obj;

extern Obj *lbl_805A0D44;

unsigned char fn_8025C3F8(void)
{
    unsigned char i;
    unsigned char c;
    Obj *ctx;

    lbl_805A0D44->ptr += 2;
    if (*lbl_805A0D44->ptr++ != 8)
        return 0xA;

    lbl_805A0D44->field694 =
        (lbl_805A0D44->ptr[0] << 8) | lbl_805A0D44->ptr[1];
    lbl_805A0D44->ptr += 2;
    lbl_805A0D44->field692 =
        (lbl_805A0D44->ptr[0] << 8) | lbl_805A0D44->ptr[1];
    lbl_805A0D44->ptr += 2;

    if (*lbl_805A0D44->ptr++ != 3)
        return 0xC;

    for (i = 0; i < 3; i++) {
        lbl_805A0D44->ptr += 1;
        c = *lbl_805A0D44->ptr++;

        if (((i == 0) && (c != 0x22)) ||
            ((i != 0) && (c != 0x11)))
            return 0x13;

        ctx = lbl_805A0D44;
        ctx->bytes[i * 6] = *ctx->ptr++;
    }

    return 0;
}
