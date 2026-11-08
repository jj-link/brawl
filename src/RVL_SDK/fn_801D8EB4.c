#pragma force_active on
int fn_801D8EB4(char *dest, char *in) {
    int mask, odd;
    char *out;
    int i, value;
    if (in) {
        out = dest;
        while (in[0] || in[1]) {
            for (i = 0; i < 4; i++) {
                odd = i & 1;
                mask = 0xf0;
                if (odd) mask = 0xf;
                value = (*in & mask) >> (unsigned char)(odd ? 0 : 4);
                if (value >= 0 && value < 10)
                    *out = value + '0';
                else if (value >= 10 && value < 16)
                    *out = value + 'a' - 10;
                else return 0;
                out++;
                if (odd) in++;
            }
        }
        *out = 0;
        return 1;
    }
    return 0;
}