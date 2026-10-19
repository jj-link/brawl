#pragma force_active on
extern "C" bool fn_24_113C(void* self) {
    int state = *(int*)((char*)self + 0x58);
    if (state == 6 || state == 9) {
        if (*(int*)((char*)self + 0x5C) >= 60)
            return true;
    }
    return false;
}
