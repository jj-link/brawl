#pragma force_active on
void fn_80211AD0(int index, int value) {
    int *p = (int *)0xCD000000;
    p += index;
    *p = value;
}
