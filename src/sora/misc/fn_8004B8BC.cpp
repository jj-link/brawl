#pragma force_active on
extern "C" int fn_8004B8BC(void* self, unsigned int arg1, int arg2) {
    unsigned char temp_r0;

    if (*(int*)((char*)self + 0x0) != 2) {
        return 1;
    }
    if (arg1 == 3) {
        if (arg2 == 0) {
            *(int*)((char*)self + 0x3C) = 0;
        } else {
            *(int*)((char*)self + 0x3C) = 1;
        }
        return 1;
    }
    if (arg1 == 4) {
        if (arg2 == 0) {
            *(int*)((char*)self + 0x3C) = 0;
            *(int*)((char*)self + 0x40) = 0;
        } else {
            *(int*)((char*)self + 0x3C) = 1;
            *(int*)((char*)self + 0x40) = 1;
        }
        return 1;
    }
    if (*(int*)((char*)self + 0x40) == 1 && arg1 == 0) {
        return 1;
    }
    temp_r0 = *(unsigned char*)((char*)self + 0x7A);
    if (temp_r0 < 7) {
        *(unsigned char*)((char*)self + (temp_r0 * 4) + 0x5E) = arg1;
        *(short*)((char*)self + (*(unsigned char*)((char*)self + 0x7A) * 4) + 0x60) = arg2;
        *(unsigned char*)((char*)self + 0x7A) = *(unsigned char*)((char*)self + 0x7A) + 1;
        switch ((int)arg1) {
        case 1:
            *(unsigned char*)((char*)self + 0x5C) = arg2;
            break;
        case 5:
            if (arg2 == 0) {
                *(int*)((char*)self + 0x3C) = 0;
            } else {
                *(int*)((char*)self + 0x3C) = 2;
            }
            break;
        }
        return 1;
    }
    return 0;
}
