#pragma force_active on
extern "C" const float lbl_88_rodata_0[];
extern "C" float getParamFloat__8BaseItemFUl(void *item, unsigned long idx);
extern "C" void setAreaSleep__9stTriggerFb(void *trigger, bool flag);
extern "C" void fn_27_233ACC(void *trigger, void *wnd);

extern "C" {
void fn_88_1A08(char *self) {
    const float *rd = lbl_88_rodata_0;
    char *item = *(char **)(self + 0x1EC);
    float threshold;
    if (item == 0 || !((*(unsigned char *)(item + 0x2C) >> 6) & 1)) {
        threshold = rd[0];
    } else {
        threshold = getParamFloat__8BaseItemFUl(item, 3);
    }
    if (*(float *)(self + 0x578) > threshold) {
        setAreaSleep__9stTriggerFb(*(void **)(self + 0x808), true);
        return;
    }
    setAreaSleep__9stTriggerFb(*(void **)(self + 0x808), false);
    float z = *(float *)(self + 0x57C);
    char *w = *(char **)(self + 0x80C);
    *(float *)(w + 0x28) = rd[1] + *(float *)(self + 0x578);
    *(float *)(w + 0x2C) = z;
    *(float *)(w + 0x30) = rd[0];
    if (*(float *)(self + 0x590) > rd[0]) {
        *(float *)(*(char **)(self + 0x80C) + 0x34) = *(float *)(self + 0x584);
    } else {
        *(float *)(*(char **)(self + 0x80C) + 0x34) = rd[0];
    }
    *(unsigned char *)(*(char **)(self + 0x80C) + 0x38) = 0;
    w = *(char **)(self + 0x80C);
    *(float *)(w + 0x18) = rd[0];
    *(float *)(w + 0x1C) = rd[0];
    *(float *)(w + 0x20) = rd[2];
    *(float *)(w + 0x24) = rd[3];
    *(int *)(w + 0x0) = 0;
    fn_27_233ACC(*(void **)(self + 0x808), *(void **)(self + 0x80C));
}
}
