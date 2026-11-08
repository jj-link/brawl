#pragma force_active on

extern "C" bool fn_27_1706FC(void* object, int value);

extern "C" bool fn_105_12FD8(void* object, int value) {
    switch (value) {
    case 0x11E:
        return false;
    }
    return fn_27_1706FC(object, value);
}