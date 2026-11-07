#pragma force_active on
typedef struct {
    char pad00[0x10];
    float x10;
    char pad14[4];
    float x18;
    float x1c;
    char pad20[4];
    float x24;
    char pad28[4];
    float x2c;
    float x30;
    char pad34[0x28];
    int x5c;
    int x60;
    int x64;
    unsigned int x68;
    int x6c;
    int x70;
} Object;

extern int fn_803EFEA4(void *, int, int);

extern const float lbl_805A4B04;
extern const float lbl_805A4B10;
extern const float lbl_805A4B14;
extern const float lbl_805A4B18;
extern const float lbl_805A4B1C;
extern const float lbl_805A4B20;
extern const float lbl_805A4B24;
extern const float lbl_805A4B28;
extern const float lbl_805A4B2C;
extern const float lbl_805A4B30;
extern const float lbl_805A4B34;
extern const float lbl_805A4B38;
extern const float lbl_805A4B3C;
extern const float lbl_805A4B40;
extern const float lbl_805A4B44;
extern const float lbl_805A4B48;
extern const float lbl_805A4B4C;
extern const float lbl_805A4B50;
extern const float lbl_805A4B54;
extern const float lbl_805A4B58;

int fn_803F004C(Object *obj, int arg1, int arg2, int arg3, int arg4)
{
    int result;
    int count;
    unsigned int seed;
    float value;

    if ((arg1 >= 0 && arg1 <= 0xcf) || arg1 >= 0x12c) {
        result = fn_803EFEA4(obj, arg1, arg2);
    } else {
        switch (arg1) {
        case 0xbe:
            result = obj->x5c;
            break;
        default:
            result = arg1;
            break;
        }
    }

    if (arg1 >= 0 && arg1 <= 0xc7 && arg1 == arg2 && arg1 != 0xc9) {
        obj->x68 = obj->x68 * 0x19660d + 0x3c6ef35f;
        result = (obj->x68 >> 2) & 0x3f;
    }

    switch (arg1) {
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0xce:
    case 0xcf:
    case 0xd3:
        obj->x6c = 0;
        obj->x18 = lbl_805A4B04;
        obj->x2c = lbl_805A4B04;
        break;
    }

    if (arg1 == 0xc9) {
        obj->x18 = lbl_805A4B04;
        obj->x2c = lbl_805A4B04;
    } else {
        switch (obj->x6c) {
        default:
            obj->x18 = lbl_805A4B04;
            obj->x2c = lbl_805A4B04;
            break;
        case 1:
            obj->x18 = lbl_805A4B10;
            obj->x2c = lbl_805A4B10;
            break;
        case 2:
            obj->x18 = lbl_805A4B14;
            obj->x2c = lbl_805A4B14;
            break;
        case 3:
            obj->x18 = lbl_805A4B18;
            obj->x2c = lbl_805A4B18;
            break;
        case 4:
            obj->x18 = lbl_805A4B1C;
            obj->x2c = lbl_805A4B1C;
            break;
        case 5:
            obj->x18 = lbl_805A4B20;
            obj->x2c = lbl_805A4B20;
            break;
        case 6:
            obj->x18 = lbl_805A4B24;
            obj->x2c = lbl_805A4B24;
            break;
        }
        obj->x6c++;
    }

    switch (arg1) {
    case 0xcd:
    case 0xce:
    case 0xcf:
    case 0xd3:
        obj->x64 = 0;
        obj->x1c = lbl_805A4B04;
        obj->x30 = lbl_805A4B04;
        break;
    }

    if (arg1 == 0xc9) {
        obj->x1c = lbl_805A4B04;
        obj->x30 = lbl_805A4B04;
    } else {
        switch (obj->x60) {
        case 0xfd:
            count = obj->x64;
            if (count == 0) {
                seed = obj->x68 * 0x19660d + 0x3c6ef35f;
                obj->x68 = seed;
                obj->x64 = ((int)(unsigned char)(seed >> 16) >> 6) + 10;
            } else {
                obj->x64 = count - 1;
            }
            switch (obj->x64) {
            case 0:
            case 1:
            case 2:
                obj->x1c = lbl_805A4B28;
                obj->x30 = lbl_805A4B28;
                obj->x10 = lbl_805A4B2C;
                obj->x24 = lbl_805A4B2C;
                break;
            case 3:
            case 4:
                obj->x1c = lbl_805A4B30;
                obj->x30 = lbl_805A4B30;
                obj->x10 = lbl_805A4B10;
                obj->x24 = lbl_805A4B10;
                break;
            case 9:
            case 10:
                obj->x1c = lbl_805A4B10;
                obj->x30 = lbl_805A4B10;
                obj->x10 = lbl_805A4B2C;
                obj->x24 = lbl_805A4B2C;
                break;
            default:
                obj->x1c = lbl_805A4B24;
                obj->x30 = lbl_805A4B24;
                obj->x10 = lbl_805A4B34;
                obj->x24 = lbl_805A4B34;
                break;
            }
            break;

        case 0xfc:
            count = obj->x64;
            if (count == 0) {
                obj->x68 = obj->x68 * 0x19660d + 0x3c6ef35f;
                obj->x64 = 1;
            } else if (count == 0) {
                obj->x64 = 0;
                if (obj->x70 == 0)
                    obj->x70 = 1;
                else
                    obj->x70 = 0;
            } else if (count > 15) {
                obj->x64 = 1;
            } else {
                obj->x64 = count + 1;
            }

            if (obj->x70 == 0)
                value = lbl_805A4B04 - lbl_805A4B38 * (float)obj->x64;
            else
                value = lbl_805A4B24 - lbl_805A4B38 * (float)obj->x64;
            if (value < lbl_805A4B3C)
                value = lbl_805A4B3C;
            obj->x1c = value;
            obj->x30 = value;

            if (obj->x70 == 0)
                value = lbl_805A4B40 - lbl_805A4B44 * (float)obj->x64;
            else
                value = lbl_805A4B04 - lbl_805A4B44 * (float)obj->x64;
            if (value < lbl_805A4B48)
                value = lbl_805A4B48;
            obj->x10 = value;
            obj->x24 = value;
            break;

        case 0xfb:
            count = obj->x64;
            if (count == 0) {
                seed = obj->x68 * 0x19660d + 0x3c6ef35f;
                obj->x68 = seed;
                obj->x64 = ((int)(unsigned char)(seed >> 16) >> 6) + 10;
            } else {
                obj->x64 = count - 1;
            }
            switch (obj->x64) {
            case 0:
            case 1:
                obj->x1c = lbl_805A4B34;
                obj->x30 = lbl_805A4B34;
                obj->x10 = lbl_805A4B34;
                obj->x24 = lbl_805A4B34;
                break;
            case 2:
                obj->x1c = lbl_805A4B40;
                obj->x30 = lbl_805A4B40;
                obj->x10 = lbl_805A4B30;
                obj->x24 = lbl_805A4B30;
                break;
            default:
                obj->x1c = lbl_805A4B30;
                obj->x30 = lbl_805A4B30;
                obj->x10 = lbl_805A4B34;
                obj->x24 = lbl_805A4B34;
                break;
            }
            break;

        default:
            obj->x1c = lbl_805A4B04;
            obj->x30 = lbl_805A4B04;
            obj->x10 = lbl_805A4B04;
            obj->x24 = lbl_805A4B04;
            break;
        }
    }

    if (arg4 != 0x20) {
        if (arg4 > 0x20) {
            value = obj->x10 + lbl_805A4B4C * (float)(arg4 - 0x20);
            if (value > lbl_805A4B50)
                value = lbl_805A4B50;
            obj->x10 = value;
            obj->x24 = value;
        } else {
            arg4 = 0x1f - arg4;
            value = obj->x10 - lbl_805A4B54 * (float)arg4;
            if (value < lbl_805A4B58)
                value = lbl_805A4B58;
            obj->x10 = value;
            obj->x24 = value;
        }
    }

    return result;
}
