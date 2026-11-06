#pragma force_active on

unsigned char *fn_801E21E8(unsigned char *s, unsigned int *out)
{
    unsigned int lead;
    unsigned int c;
    unsigned int cp;
    unsigned int n;
    unsigned int i;

    lead = *s;
    if (lead != 0) {
        s++;
    }
    if (!(lead & 0x80)) {
        n = 0;
    } else if ((lead & 0xE0) == 0xC0) {
        lead &= 0x1F;
        n = 1;
    } else if ((lead & 0xF0) == 0xE0) {
        lead &= 0x0F;
        n = 2;
    } else if ((lead & 0xF8) == 0xF0) {
        lead &= 0x07;
        n = 3;
    } else {
        return 0;
    }

    cp = lead;
    for (i = 0; i < n; i++) {
        c = *s;
        cp <<= 6;
        s++;
        if ((c & 0xC0) != 0x80) {
            return 0;
        }
        cp |= (c & 0x3F);
    }

    if (cp <= 0x7F) {
        if (n != 0) {
            return 0;
        }
    } else if (cp <= 0x7FF) {
        if (n != 1) {
            return 0;
        }
    } else if (cp <= 0xFFFF) {
        if (n != 2) {
            return 0;
        }
    }

    if (cp >= 0xD800 && cp <= 0xDFFF) {
        return 0;
    }

    *out = cp;
    return s;
}
