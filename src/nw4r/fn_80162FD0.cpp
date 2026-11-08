#pragma force_active on
extern "C" {
double fn_80400AB8(double);
void fn_80163084(int, int, float, float, float, float, float, float);
}
extern "C" void fn_80162FD0(int a, int b, float x, float y, float z, float w) {
    float result = (float)fn_80400AB8(0.02454369328916073f * (0.7111111283302307f * (0.5f * x)));
    float p = result * z;
    float q = p * y;
    fn_80163084(a, b, p, -p, -q, q, z, w);
}