#pragma force_active on
extern "C" {

int fn_801AEEF8(unsigned char* obj, int a, int b);

int fn_801B269C(unsigned char* self, int type, int value) {
    switch (type) {
    case 0x00030001:
        if (value != 0) {
            *(unsigned int*)(self + 0x13c) &= ~2u;
        } else {
            *(unsigned int*)(self + 0x13c) |= 2;
        }
        break;
    default:
        return fn_801AEEF8(self, type, value);
    }
    return 1;
}

}
