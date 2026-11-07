#pragma force_active on

extern "C" int fn_27_7B610();

extern "C" int fn_27_2BDF8C(void* self, int value) {
    switch (value) {
    case 1000:
        return 1;
    default:
        return fn_27_7B610();
    }
}
