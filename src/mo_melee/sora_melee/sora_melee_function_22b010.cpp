#pragma force_active on
#pragma scheduling off

extern "C" int fn_27_22B010(void* obj, void* arr, void* target, int* out)
{
    unsigned int count = *(unsigned int*)((char*)obj + 0x50);
    char* p = (char*)arr;
    unsigned int idx = 0;

    for (; idx < count; idx++) {
        unsigned int value = *(unsigned int*)p;
        if (value != 0 && (unsigned int)target == value) {
            *out = (int)idx;
            return 1;
        }
        p += 0x10;
    }

    idx = 0;
    for (; idx < count; idx++) {
        if (*(unsigned int*)arr == 0) {
            *out = (int)idx;
            return 0;
        }
        arr = (void*)((char*)arr + 0x10);
    }

    *out = (int)count;
    return 0;
}
