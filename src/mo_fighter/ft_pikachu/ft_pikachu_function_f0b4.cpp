#pragma force_active on
extern "C" double atan2(double, double);

extern "C" float fn_98_F0B4(double y, double x) {
    return static_cast<float>(atan2(y, x));
}
