#pragma force_active on
extern int lbl_804F6810[];
extern int fn_802372F0(int);

int fn_80219F3C(int idx, int flag) {
    int p = lbl_804F6810[idx];
    if (flag == -1) {
        return p;
    }
    return fn_802372F0(*(unsigned char*)(p + 0x8c3));
}
