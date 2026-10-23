#pragma force_active on
extern "C" int fn_801AEF40(void* self, int type, int* out);

extern "C" int fn_801B26E4(void* self, int type, int* out) {
    if (out == 0)
        return 0;

    switch (type) {
    case 0x30001: {
        unsigned int val = *(unsigned int*)((char*)self + 0x13c);
        *out = !(val & 0x2);
        break;
    }
    default:
        return fn_801AEF40(self, type, out);
    }

    return 1;
}
