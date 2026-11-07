#pragma force_active on
extern const float lbl_27_rodata_2F68[];

extern "C" int fn_27_207364(int a, unsigned int b, int c, float f)
{
    const float* k = lbl_27_rodata_2F68;
    if (a == 0x16 && f >= k[2]) {
        return 1;
    }
    switch (b) {
    case 0:
        switch (a) {
        case 0x113:
        case 0x114:
            return 0x12;
        }
        break;
    case 1:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x115:
        case 0x130:
        case 0x131:
        case 0x132:
            return 0x12;
        case 0x112:
        case 0x12e:
            return 0x13;
        case 0x117:
        case 0x118:
            return 1;
        case 0x11d:
            return 2;
        case 0x120:
        case 0x121:
        case 0x122:
        case 0x123:
        case 0x124:
        case 0x125:
        case 0x126:
        case 0x127:
        case 0x128:
        case 0x129:
            return 0xa;
        case 0x12a:
        case 0x12b:
        case 0x12c:
        case 0x12d:
            return 0xb;
        }
        break;
    case 2:
        switch (a) {
        case 0x118:
            return 0x12;
        case 0x114:
        case 0x117:
            return 0x13;
        }
        break;
    case 41:
        switch (a) {
        case 0x118:
            return 0x12;
        case 0x114:
        case 0x117:
            return 0x13;
        }
        break;
    case 3:
        switch (a) {
        case 0x114:
            return 0x12;
        case 0x112:
        case 0x117:
        case 0x118:
            return 0x13;
        }
        break;
    case 4:
        switch (a) {
        case 0x113:
        case 0x115:
        case 0x119:
        case 0x11a:
        case 0x11b:
        case 0x11c:
            return 0x12;
        case 0x112:
        case 0x117:
        case 0x118:
            return 0x14;
        }
        break;
    case 5:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x115:
            return 0x12;
        case 0x112:
        case 0x117:
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x1ba) {
            return 0x12;
        }
        break;
    case 6:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x115:
            return 0x12;
        }
        if (a >= 0x117 && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 19:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x115:
            return 0x12;
        }
        if (a >= 0x117 && a <= 0x119) {
            return 0x12;
        }
        break;
    case 44:
        switch (a) {
        case 0x112:
        case 0x113:
        case 0x114:
        case 0x115:
            return 0x12;
        }
        if (a >= 0x117 && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 7:
        switch (a) {
        case 0x114:
            return 0x12;
        case 0x113:
        case 0x119:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 8:
        switch (a) {
        case 0x114:
        case 0x115:
            return 0x12;
        case 0x113:
        case 0x117:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x11b) {
            return 0x12;
        }
        break;
    case 9:
        switch (a) {
        case 0x113:
        case 0x115:
            return 0x12;
        case 0x112:
        case 0x117:
            if (f < k[3]) {
                return 0x13;
            }
            return 0x12;
        case 0x114:
        case 0x119:
        case 0x11a:
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 20:
        switch (a) {
        case 0x113:
        case 0x115:
            return 0x12;
        case 0x112:
        case 0x117:
            if (f < k[4]) {
                return 0x13;
            }
            return 0x12;
        case 0x114:
        case 0x11c:
        case 0x11d:
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x11f) {
            return 0x12;
        }
        break;
    case 10:
        switch (a) {
        case 0x113:
        case 0x11a:
            return 0x12;
        }
        break;
    case 26:
        switch (a) {
        case 0x113:
        case 0x11a:
            return 0x12;
        }
        break;
    case 11:
        switch (a) {
        case 0x114:
        case 0x115:
            return 0x12;
        case 0x113:
            return 0x14;
        }
        if (a >= 0x11c && a <= 0x121) {
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x11b) {
            return 0x12;
        }
        break;
    case 48:
        switch (a) {
        case 0x114:
        case 0x115:
            return 0x12;
        case 0x113:
            return 0x14;
        }
        if (a >= 0x11c && a <= 0x121) {
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x11b) {
            return 0x12;
        }
        break;
    case 12:
        switch (a) {
        case 0x113:
        case 0x114:
            return 0x12;
        case 0x11e:
            switch (c) {
            case 0x62:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
                return 0x12;
            }
            break;
        }
        if (a >= 0x117 && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 13:
        switch (a) {
        case 0x112:
            return 0x12;
        }
        break;
    case 14:
        switch (a) {
        case 0x113:
        case 0x114:
            return 0x12;
        case 0x112:
        case 0x117:
            return 0x13;
        }
        if (a >= 0x11a && a <= 0x11d) {
            return 0x12;
        }
        break;
    case 15:
    case 16:
        switch (a) {
        case 0x113:
            return 0x12;
        }
        break;
    case 17:
        if (a >= 0x117 && a <= 0x11c) {
            return 0x12;
        }
        switch (a) {
        case 0x113:
        case 0x114:
            return 0x12;
        case 0x112:
        case 0x117:
            return 0x13;
        }
        break;
    case 34:
        switch (a) {
        case 0x114:
            return 0x12;
        case 0x112:
        case 0x113:
        case 0x117:
        case 0x11a:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x120) {
            return 0x12;
        }
        break;
    case 18:
        switch (a) {
        case 0x113:
        case 0x114:
            return 0x12;
        }
        if (a >= 0x117 && a <= 0x118) {
            return 0x12;
        }
        break;
    case 21:
    case 49:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x115:
            return 0x12;
        case 0x112:
        case 0x117:
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x12f) {
            return 0x12;
        }
        break;
    case 22:
        switch (a) {
        case 0x112:
        case 0x113:
        case 0x114:
            return 0x12;
        }
        if (a >= 0x117 && a <= 0x11e) {
            return 0x12;
        }
        break;
    case 23:
        switch (a) {
        case 0x113:
            return 0x12;
        }
        if (a >= 0x11b && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 24:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x11b:
        case 0x11f:
            return 0x12;
        }
        break;
    case 25:
        switch (a) {
        case 0x114:
            return 0x12;
        }
        break;
    case 27:
        switch (a) {
        case 0x114:
            return 0x12;
        case 0x117:
            return 0x13;
        case 0x113:
        case 0x11b:
            return 0x14;
        }
        if (a >= 0x11b && a <= 0x129) {
            return 0x12;
        }
        break;
    case 29:
        switch (a) {
        case 0x114:
            return 0x12;
        }
        break;
    case 30:
        switch (a) {
        case 0x113:
        case 0x114:
            return 0x12;
        case 0x112:
        case 0x117:
        case 0x118:
            return c == 0x1d1 ? 0x12 : 0;
        }
        if (a >= 0x119 && a <= 0x11c) {
            return 0x12;
        }
        break;
    case 31:
        switch (a) {
        case 0x112:
        case 0x114:
            return 0x12;
        }
        if (a >= 0x117 && a <= 0x118) {
            return 0x12;
        }
        break;
    case 32:
        switch (a) {
        case 0x114:
        case 0x115:
        case 0x137:
            return 0x12;
        case 0x112:
        case 0x117:
            return 0x14;
        }
        if (a >= 0x117 && a <= 0x128) {
            return 0x12;
        }
        if (a >= 0x12a && a <= 0x12e) {
            return 0x12;
        }
        break;
    case 33:
        switch (a) {
        case 0x113:
            if (f < k[5]) {
                return 0x14;
            }
            return 0x12;
        case 0x112:
        case 0x117:
        case 0x118:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x11a) {
            return 0x12;
        }
        break;
    case 35:
        switch (a) {
        case 0x112:
        case 0x113:
            return 0x12;
        case 0x115:
        case 0x11b:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x118) {
            return 0x12;
        }
        break;
    case 37:
        switch (a) {
        case 0x113:
        case 0x114:
        case 0x115:
            return 0x12;
        case 0x112:
        case 0x117:
        case 0x118:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x11d) {
            return 0x12;
        }
        break;
    case 47:
        switch (a) {
        case 0x112:
        case 0x125:
            return 0x12;
        case 0x113:
        case 0x115:
        case 0x11d:
        case 0x124:
            return 0x13;
        }
        if (a >= 0x117 && a <= 0x122) {
            return 0x12;
        }
        break;
    }
    return 0;
}
