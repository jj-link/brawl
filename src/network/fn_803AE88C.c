#pragma force_active on
int fn_803AE88C(void *arg0, void **arg1) {
    void *var = *(void **)((char *)arg0 + 0x24);
    while (var != arg0) {
        if (!(*(unsigned short *)var & 1)) {
            *arg1 = var;
            return 1;
        }
        if ((unsigned)(*(int *)((char *)var + 0x18) + 0x10000) != 0xffff) {
            *arg1 = var;
            return 0;
        }
        var = *(void **)((char *)var + 0x24);
    }
    if (!(*(unsigned short *)var & 1)) {
        *arg1 = var;
        return 1;
    }
    if ((unsigned)(*(int *)((char *)var + 0x18) + 0x10000) != 0xffff) {
        *arg1 = var;
        return 0;
    }
    *arg1 = 0;
    return 0;
}
