#pragma force_active on

extern "C" int fn_8018990C(void *arg0) {
    int *p = (int*)arg0;
    return p[16] + (((unsigned int)p[14]) >> 28) * 0x1C;
}
