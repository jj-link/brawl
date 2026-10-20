#pragma force_active on
extern "C" bool fn_66_5370(unsigned char* self) {
    bool result = false;
    switch (self[0x150]) {
    case 0x13:
        self[0x15D] = 1;
        result = true;
        break;
    }
    return result;
}
