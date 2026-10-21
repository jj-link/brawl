#pragma force_active on
unsigned int fn_803A9AA8(void* arg0, unsigned int arg1) {
    unsigned int* p = (unsigned int*)arg0;

    if (arg1 == 1) {
        return p[0];
    }
    if (arg1 == 2) {
        return p[1];
    }
    return p[2];
}
