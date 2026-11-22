#pragma force_active on
void fn_80379650(unsigned char *key, int keylen, unsigned char *data, int len)
{
    unsigned char s[256];
    short i;
    unsigned char k, j, t;

    for (i = 0; i < 256; i++) {
        s[i] = i;
    }

    k = 0;
    j = 0;
    for (i = 0; i < 256; i++) {
        j = (unsigned char)((j + s[i] + key[k]) % 256);
        t = s[i];
        k = (unsigned char)((k + 1) % keylen);
        s[i] = s[j];
        s[j] = t;
    }

    {
        unsigned char v, x = 0, y = 0;
        unsigned char *state = s;

        for (keylen = 0; (short)keylen < len;) {
            int index = (short)keylen++;
            v = data[index];
            x = (x + v + 1) % 256;
            t = state[x];
            y = (t + y) % 256;
            state[x] = state[y];
            state[y] = t;
            data[index] ^= state[(unsigned char)((s[x] + t) % 256)];
        }
    }
}
