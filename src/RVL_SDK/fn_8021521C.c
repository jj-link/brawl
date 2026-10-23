#pragma force_active on
extern int fn_80212938(int, int);

int fn_8021521C(int a, int b) {
    if (b == 0)
        goto fail;
    if ((b & 0x1F) == 0)
        goto done;
fail:
    return -0x65;
done:
    return fn_80212938(a, b);
}
