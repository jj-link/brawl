#pragma force_active on
extern "C" int fn_27_21A100(void *p) {
    if (*(signed char *)((char *)p + 0xA) != 0)
        return -1;
    return *(int *)((char *)p + 4);
}
