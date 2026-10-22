#pragma force_active on
double sin(double);
double cos(double);
void fn_801EC708(int, int, float, float);

void fn_801EC7B8(int arg0, int arg1, float farg0) {
    float temp_f31;

    temp_f31 = (float) sin(farg0);
    fn_801EC708(arg0, arg1, temp_f31, (float) cos(farg0));
}
