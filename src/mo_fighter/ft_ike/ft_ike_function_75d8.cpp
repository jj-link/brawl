#pragma force_active on
extern "C" {
int fn_119_74EC(int a, int b);

int fn_119_75D8(int a, int b)
{
    switch (b) {
    case 0:
        return a;
    case 1:
        return a + 0x4a8;
    case 2:
        return fn_119_74EC(a, b);
    default:
        return fn_119_74EC(a, b);
    }
}
}
