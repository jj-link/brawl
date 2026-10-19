#pragma force_active on
extern "C" int fn_14_3D28(int mode, int value, int index)
{
    int result = mode;
    switch (mode) {
    case 0:
        if (value == 0)
            result = 0;
        else
            result = 1;
        break;
    case 1:
        result = index + 2;
        break;
    case 2:
        result = 6;
        break;
    }
    return result;
}
