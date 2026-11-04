#pragma force_active on
extern "C" int fn_801AAE34(void* self, int type, int* out) {
    if (out == 0)
        return 0;
    switch (type) {
    case 1:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 4) & 1;
        break;
    case 2:
        *out = *(unsigned int*)((char*)self + 0xCC) & 1;
        break;
    case 3:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 1) & 1;
        break;
    case 4:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 2) & 1;
        break;
    case 5:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 3) & 1;
        break;
    case 6:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 5) & 1;
        break;
    case 7:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 6) & 1;
        break;
    case 8:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 7) & 1;
        break;
    case 9:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 28) & 1;
        break;
    default:
        return 0;
    }
    return 1;
}