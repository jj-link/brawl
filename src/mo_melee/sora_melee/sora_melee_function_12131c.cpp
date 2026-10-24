#pragma force_active on

extern "C" int fn_27_12131C(char* self, int type, unsigned int sub, int sub2, unsigned int mask, int pref, int start) {
    char* base;
    int offset;
    char* e;
    int i;
    int count;
    int inRange;

    if (pref != -1) {
        inRange = 0;
        if (type >= 0x2E && type <= 0x31) inRange = 1;
        if (inRange == 0) {
            char* p = *(char**)self + pref * 0x4D4;
            if ((unsigned char)p[0x159] == 0 && type == *(int*)(p + 0x160) && sub == (unsigned char)p[0x15B]) {
                if (mask == 0 || mask == (mask & *(unsigned int*)(p + sub2 * 0x54 + 0xC))) return pref;
            }
        }
    }

    count = *(int*)(self + 4);
    i = start;
    for (int j = 0; j < count; j++) {
        offset = i * 0x4D4;
        base = *(char**)self;
        e = base + offset;
        if ((unsigned char)e[0x159] == 0 && type == *(int*)(e + 0x160) && sub == (unsigned char)e[0x15B]) {
            if (mask == 0 || mask == (mask & *(unsigned int*)(offset + (base + sub2 * 0x54) + 0xC))) return i;
        }
        i++;
        if (i >= count) i = 0;
    }

    inRange = 0;
    if (type >= 0x2E && type <= 0x31) inRange = 1;
    i = start;
    if (inRange != 0) {
        for (int j = 0; j < count; j++) {
            base = *(char**)self;
            e = base + i * 0x4D4;
            if ((unsigned char)e[0x15D] == 0 && type == *(int*)(e + 0x160) && sub == (unsigned char)e[0x15B]) return i;
            i++;
            if (i >= count) i = 0;
        }
    } else {
        for (int j = 0; j < count; j++) {
            base = *(char**)self;
            e = base + i * 0x4D4;
            if ((unsigned char)e[0x159] == 0 && type == *(int*)(e + 0x160) && sub == (unsigned char)e[0x15B]) return i;
            i++;
            if (i >= count) i = 0;
        }
    }
    return -1;
}
