#pragma force_active on
typedef unsigned int u32;

static inline int update_suffix(char *buf, u32 num, int i, int j,
                                u32 ext, u32 end, u32 *count,
                                u32 *position)
{
    char digits[8];
    char *p = digits;
    char *dst, *src;

    *count = 0;
    while (num != 0) {
        *p++ = num % 10 + '0';
        num /= 10;
        (*count)++;
    }

    if (i + (*count) >= ext) {
        (*position) = i + (*count) + 1;
        if ((*position) > 8)
            (*position) = 8;

        *(buf + (*position) + 4) = buf[end];
        *(buf + (*position) + 3) = *(buf + ext + 2);
        *(buf + (*position) + 2) = *(buf + ext + 1);
        *(buf + (*position) + 1) = buf[ext];
        buf[(*position)] = buf[j];
    }

    if (i + (*count) >= 8)
        i = 7 - (*count);

    buf[i++] = 0x7E;
    src = digits + (*count);
    dst = buf + i;

    while ((*count) > 0) {
        *dst++ = *--src;
        (*count)--;
    }

    return 0;
}

int fn_803BF730(char *buf, u32 num)
{
    int i, j;
    u32 n, ext, end, pos;

    if (num == 0)
        return 0;

    i = 1;
    while (buf[i] != 0x7E)
        i++;

    j = i + 1;
    while (buf[j] != '.' && buf[j] != 0)
        j++;

    ext = j + 1;
    if (buf[j] == '.' && buf[ext] != 0) {
        end = ext + 1;
        while (buf[end] != 0)
            end++;
    } else {
        end = ext;
    }

    return update_suffix(buf, num, i, j, ext, end, &n, &pos);
}
