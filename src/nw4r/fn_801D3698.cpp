#pragma force_active on
extern "C" {

int fn_801D3698(int arg0, int arg1, int arg2) {
    if (arg0 == 1) {
        return arg1 + arg2;
    }
    int result = 0;
    if (arg0 == 0) {
        result = arg1;
    }
    return result;
}

}
