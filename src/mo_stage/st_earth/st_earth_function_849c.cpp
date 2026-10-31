#pragma force_active on

extern "C" void fn_66_849C(unsigned char* self, unsigned int value) {
    if ((int)self[0x150] != 0x13) {
        return;
    }

    self[0x159] = 0;

    switch (self[0x158]) {
    case 0:
        switch (value) {
        case 0: self[0x160] = 2; break;
        case 1: self[0x160] = 1; break;
        case 2: self[0x160] = 1; break;
        case 3: self[0x160] = 3; break;
        case 4: self[0x160] = 2; break;
        case 5: self[0x160] = 2; break;
        case 6: self[0x160] = 4; break;
        case 7: self[0x160] = 3; break;
        case 8: self[0x160] = 3; break;
        }
        break;

    case 1:
        switch (value) {
        case 0: self[0x160] = 1; break;
        case 1: self[0x160] = 2; break;
        case 2: self[0x160] = 1; break;
        case 3: self[0x160] = 2; break;
        case 4: self[0x160] = 3; break;
        case 5: self[0x160] = 2; break;
        case 6: self[0x160] = 3; break;
        case 7: self[0x160] = 4; break;
        case 8: self[0x160] = 3; break;
        }
        break;

    case 2:
        switch (value) {
        case 0: self[0x160] = 1; break;
        case 1: self[0x160] = 1; break;
        case 2: self[0x160] = 2; break;
        case 3: self[0x160] = 2; break;
        case 4: self[0x160] = 2; break;
        case 5: self[0x160] = 3; break;
        case 6: self[0x160] = 3; break;
        case 7: self[0x160] = 3; break;
        case 8: self[0x160] = 4; break;
        }
        break;
    }

    unsigned char v = self[0x160];
    if (v == 0 || v >= 5U) {
        return;
    }
    self[0x150] = 0x16;
}
