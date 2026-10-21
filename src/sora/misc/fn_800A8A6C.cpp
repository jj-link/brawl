#pragma force_active on

typedef unsigned char u8;

extern "C" void fn_800A8A6C(u8* base, int unused, int* index, const u8* input) {
    int action;
    u8 flags = *input;

    if (flags & 0x10) {
        action = 1;
    } else if (flags & 4) {
        action = 2;
    } else {
        action = 0;
        if (flags & 8) {
            action = 3;
        }
    }

    switch (action) {
    case 0:
        break;
    case 1:
        *index = -1;
        return;
    case 2:
        if (*index < -1) {
            *index = -1;
        }
        do {
            ++*index;
            if (*index >= 4) {
                *index = -1;
                return;
            }
        } while (!((base[0x78 + *index * 0x10] >> 7) & 1));
        return;
    case 3:
        if (*index < 0) {
            *index = 4;
        }
        do {
            --*index;
            if (*index < 0) {
                *index = -1;
                return;
            }
        } while (!((base[0x78 + *index * 0x10] >> 7) & 1));
        return;
    }
}
