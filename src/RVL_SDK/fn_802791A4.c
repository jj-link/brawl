#pragma force_active on
void fn_802791A4(char *base, int off, char val) {
    *(char*)(base + off + 4) = val;
}
