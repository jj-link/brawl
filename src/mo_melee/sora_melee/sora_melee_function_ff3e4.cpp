#pragma force_active on
extern "C" void *fn_27_FF3E4(void *p, int index) {
    int count = *(int *)((char *)p + 8);
    int adjusted = (count >> 30) + index;
    if (adjusted >= 1)
        adjusted--;
    return (char *)p + adjusted * 12 + 12;
}
