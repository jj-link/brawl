#include <types.h>
#pragma force_active on
extern "C" int fn_80053F4C(void*);
extern "C" int fn_80054034(void* p) {
    unsigned char* base = (unsigned char*)p;
    int val = fn_80053F4C(p);
    unsigned char* e;
    bool matched[4];
    unsigned char* bp;
    bool* m;
    unsigned char* entry;
    int b;
    int i;
    int cnt;
    unsigned char* scanEntry;
    int scanIndex;
    int best = 4;
    int found = 0;
    if (base[2] == 1) {
        e = base + 0x24;
        entry = e;
        m = matched;
        for (i = 0; i < 4; entry += 0x2AC, m++, i++) {
            if (entry[1] != 3 && val == (int)*(base + entry[6] * 0x30 + 0x1304)) {
                found = 1;
                best = i;
                *m = 1;
            } else {
                *m = 0;
            }
        }
    } else {
        e = base + 0x24;
        entry = e;
        m = matched;
        for (i = 0; i < 4; entry += 0x2AC, m++, i++) {
            if (entry[1] != 3 && (int)entry[0xE] == val) {
                if (best != 4) found = 1;
                if (best == 4) best = i;
                *m = 1;
            } else {
                *m = 0;
            }
        }
    }
    if (!found) return best;
    {
    scanEntry = e;
    m = matched;
    b = 4;
    for (scanIndex = 0; scanIndex < 4; m++, scanEntry += 0x2AC, scanIndex++) {
        if (*m) {
            if (b == 4)
                b = scanIndex;
            else if (*(unsigned int*)(base + b * 0x2AC + 0x24 + 16) > *(unsigned int*)(scanEntry + 16))
                b = scanIndex;
            bp = base + b * 0x2AC + 0x24;
        }
    }
    cnt = 0;
    scanEntry = e;
    for (i = 0; i < 4; i++, scanEntry += 0x2AC) {
        if (matched[i] && b != i) {
            if (*(unsigned int*)(scanEntry + 16) == *(unsigned int*)(bp + 16))
                cnt++;
            else
                matched[i] = false;
        }
    }
    if (!cnt) return b;
    }
    {
    scanEntry = e;
    m = matched;
    b = 4;
    for (scanIndex = 0; scanIndex < 4; m++, scanEntry += 0x2AC, scanIndex++) {
        if (*m) {
            if (b == 4)
                b = scanIndex;
            else if (*(unsigned int*)(base + b * 0x2AC + 0x24 + 20) < *(unsigned int*)(scanEntry + 20))
                b = scanIndex;
            bp = base + b * 0x2AC + 0x24;
        }
    }
    cnt = 0;
    scanEntry = e;
    for (i = 0; i < 4; i++, scanEntry += 0x2AC) {
        if (matched[i] && b != i) {
            if (*(unsigned int*)(scanEntry + 20) == *(unsigned int*)(bp + 20))
                cnt++;
            else
                matched[i] = false;
        }
    }
    if (!cnt) return b;
    }
    {
    scanEntry = e;
    m = matched;
    b = 4;
    for (scanIndex = 0; scanIndex < 4; m++, scanEntry += 0x2AC, scanIndex++) {
        if (*m) {
            if (b == 4)
                b = scanIndex;
            else if (*(unsigned int*)(base + b * 0x2AC + 0x24 + 464) > *(unsigned int*)(scanEntry + 464))
                b = scanIndex;
            bp = base + b * 0x2AC + 0x24;
        }
    }
    cnt = 0;
    scanEntry = e;
    for (i = 0; i < 4; i++, scanEntry += 0x2AC) {
        if (matched[i] && b != i) {
            if (*(unsigned int*)(scanEntry + 464) == *(unsigned int*)(bp + 464))
                cnt++;
            else
                matched[i] = false;
        }
    }
    if (!cnt) return b;
    }
    {
    scanEntry = e;
    m = matched;
    b = 4;
    for (scanIndex = 0; scanIndex < 4; m++, scanEntry += 0x2AC, scanIndex++) {
        if (*m) {
            if (b == 4)
                b = scanIndex;
            else if (*(unsigned int*)(base + b * 0x2AC + 0x24 + 652) < *(unsigned int*)(scanEntry + 652))
                b = scanIndex;
            bp = base + b * 0x2AC + 0x24;
        }
    }
    cnt = 0;
    scanEntry = e;
    for (i = 0; i < 4; i++, scanEntry += 0x2AC) {
        if (matched[i] && b != i) {
            if (*(unsigned int*)(scanEntry + 652) == *(unsigned int*)(bp + 652))
                cnt++;
            else
                matched[i] = false;
        }
    }
    if (!cnt) return b;
    }
    for (i = 0; i < 4; i++) {
        if (matched[i]) return i;
    }
    return 0;
}
