extern "C" int fn_801AAE34(void* self, int type, int* out);

#pragma force_active on
extern "C" int fn_801AB244(void* self, int type, int* out) {
    if (out == 0)
        return 0;

    switch (type) {
    case 0x10001: {
        unsigned int flags = *(unsigned int*)((char*)self + 0xcc);
        unsigned int masked = flags & 0x60;
        *out = (unsigned int)(-masked | masked) >> 31;
        break;
    }
    default:
        return fn_801AAE34(self, type, out);
    }

    return 1;
}
