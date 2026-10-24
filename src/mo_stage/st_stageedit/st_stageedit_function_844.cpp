#pragma force_active on
extern "C" int fn_85_844(void* self, unsigned int category, unsigned int kind)
{
    int result;
    if (category == 1)
        result = 0x10;
    else if (category == 3 && kind == 9)
        result = 0x10;
    else
        result = 0;
    if ((int)category == 0 && kind == 5)
        result |= 0x80;
    if (category == 1)
        result |= 0x800;
    if (category == 3) {
        switch (kind) {
        case 1:
        case 2:
            return result | 0x1020;
        case 3:
            return result | 0x20;
        case 4:
            return result | 3;
        case 6:
            return result | 0x420;
        case 7:
            return result | 0x21;
        case 8:
            return result | 0x40;
        case 9:
            result |= 2;
        default:
            return result;
        }
    }
    return result;
}