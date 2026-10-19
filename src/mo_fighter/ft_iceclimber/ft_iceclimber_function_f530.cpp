#pragma force_active on
extern "C" void* fn_105_F530(void* object, int index) {
    if (index == 4) {
        return static_cast<char*>(object) + 0x8f6c;
    }
    if (index == 3) {
        return static_cast<char*>(object) + 0x6b98;
    }
    if (index == 2) {
        return static_cast<char*>(object) + 0x47c4;
    }
    if (index == 1) {
        return static_cast<char*>(object) + 0x23f0;
    }
    if (index == 0) {
        return static_cast<char*>(object) + 0x1c;
    }
    return 0;
}
