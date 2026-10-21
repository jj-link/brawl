#pragma force_active on
extern "C" {

int fn_80041920(float* a, float* b) {
    int result = 0;
    if (a[2] < b[2]) goto end;
    if (a[0] > b[0]) goto end;
    if (a[3] < b[3]) goto end;
    if (a[1] > b[1]) goto end;
    result = 1;
end:
    return result;
}

}
