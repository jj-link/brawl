#pragma force_active on
extern "C" {
int fn_102_7DE0(int a, int b);
}

extern "C" int fn_102_7ECC(int a, int b)
{
    switch (b) {
    case 0:
        return a;
    case 1:
        return a + 0x498;
    case 2:
        return fn_102_7DE0(a, b);
    default:
        return fn_102_7DE0(a, b);
    }
}
