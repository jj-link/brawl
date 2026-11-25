#pragma force_active on
extern "C" int fn_8006CF54(char* data, int* out1, char* out2, int* out3) {
    unsigned char* u;
    char* p = data;
    int count = 0;

    while (*p) {
        int c0 = *(unsigned char*)p;
        if (c0 < 0x20) {
            switch (*p) {
            case 10:
                p++;
                if (out1 == 0) continue;
                *out1 = 2;
                goto done;
            case 16:
                p += 3;
                break;
            case 2:
                p += 2;
                break;
            case 11: {
                u = (unsigned char*)p;
                int a = u[1];
                int b = u[2];
                p = p + a;
                p = p + b;
                p += 3;
                break;
            }
            case 29:
                p += 2;
                break;
            case 28:
                p += 3;
                break;
            case 18:
                p += 2;
                break;
            case 19:
                p += 1;
                break;
            case 17:
                p += 5;
                break;
            case 7:
                p += 2;
                break;
            case 8:
                p += 2;
                break;
            case 4:
            case 12:
                p += 5;
                break;
            case 3:
                p += 3;
                break;
            case 27:
                p += 2;
                break;
            case 13:
                p += 3;
                break;
            case 14:
                p += 2;
                break;
            case 15:
                p += 3;
                break;
            case 20: {
                unsigned char flags = (unsigned char)p[1];
                p += 2;
                if (flags & 1) p += 2;
                if (flags & 2) p += 2;
                if (flags & 4) p += 2;
                break;
            }
            case 22: {
                unsigned char flags = (unsigned char)p[1];
                p += 2;
                if (flags & 1) p += 4;
                if (flags & 2) p += 4;
                if (flags & 4) p += 4;
                break;
            }
            default:
                goto done;
            }
        } else {
            count++;
            if (out1 != 0) {
                *out1 = 1;
                unsigned char c = (unsigned char)*p;
                if (!(c & 0x80)) {
                    out2[0] = c;
                    if (*p == 0x2E && p[1] == 0x2E &&
                        p[2] == 0x2E && p[3] == 0x2E) {
                        p += 4;
                        out2[3] = 0x2E;
                        out2[2] = 0x2E;
                        out2[1] = 0x2E;
                    } else {
                        p += 1;
                        out2[1] = 0;
                    }
                    goto done;
                }
                if ((c & 0xE0) == 0xC0) {
                    out2[0] = c;
                    out2[1] = p[1];
                    out2[2] = 0;
                    p += 2;
                    goto done;
                }
                if ((c & 0xF0) == 0xE0) {
                    out2[0] = c;
                    out2[1] = p[1];
                    out2[2] = p[2];
                    out2[3] = 0;
                    p += 3;
                }
                goto done;
            }
            if (!(*p & 0x80)) {
                p += 1;
            } else if ((*p & 0xE0) == 0xC0) {
                p += 2;
            } else if ((*p & 0xF0) == 0xE0) {
                p += 3;
            }
        }
    }

done:
    if (out3 != 0) {
        *out3 = count;
    }
    return p - data;
}
