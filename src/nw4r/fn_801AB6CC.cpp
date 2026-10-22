#pragma force_active on
extern "C" void* fn_80204E5C(void* owner, unsigned int size);
extern "C" void fn_801AAB2C(void* obj, void* owner);
extern "C" char lbl_80466270[];

extern "C" void* fn_801AB6CC(void* owner, unsigned int* outSize, unsigned int count) {
    unsigned int size = (count * 4 + 0xEB) & ~3;
    char* result = 0;

    if (outSize != 0) {
        *outSize = size;
    }
    if (owner != 0) {
        result = (char*)fn_80204E5C(owner, size);
        if (result == 0) {
            return 0;
        }
        if (result != 0) {
            fn_801AAB2C(result, owner);
            *(char**)(result + 0x0) = lbl_80466270;
            *(char**)(result + 0xDC) = result + 0xE8;
            *(unsigned int*)(result + 0xE0) = count;
            *(unsigned int*)(result + 0xE4) = 0;
            *(unsigned int*)(result + 0xCC) = *(unsigned int*)(result + 0xCC) | 0x60000000;
        }
    }
    return result;
}
