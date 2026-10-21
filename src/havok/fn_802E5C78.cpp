#pragma force_active on
extern "C" void fn_802E5C78(void *arg0, void *arg1) {
    float* dst = (float*)arg0;
    float* src = (float*)arg1;
    float a = src[5];
    float c = src[10];
    float b = src[0];
    b = (b < a) ? b : a;
    b = (b < c) ? b : c;
    dst[52] = b;
    dst[53] = b;
    dst[54] = b;
}
