#pragma force_active on
extern "C" int fn_8004B780(int* object, int value) {
    int result = 0;
    if (object[1] == 0) {
        object[1] = value;
        result = 1;
    } else if (object[2] == 0) {
        object[2] = value;
        result = 1;
    } else if (object[3] == 0) {
        object[3] = value;
        result = 1;
    } else if (object[4] == 0) {
        object[4] = value;
        result = 1;
    } else if (object[5] == 0) {
        object[5] = value;
        result = 1;
    } else if (object[6] == 0) {
        object[6] = value;
        result = 1;
    } else if (object[7] == 0) {
        object[7] = value;
        result = 1;
    } else if (object[8] == 0) {
        object[8] = value;
        result = 1;
    }
    return result;
}
