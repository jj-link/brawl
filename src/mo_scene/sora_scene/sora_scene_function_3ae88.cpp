#pragma force_active on
extern "C" int fn_1_3AE88(void* arg0) {
    int result = 0;
    unsigned int state = *(unsigned int*)((char*)arg0 + 0x14);
    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 21:
        result = 1;
    default:
        return result;
    }
}
