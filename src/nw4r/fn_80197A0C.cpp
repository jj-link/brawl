#pragma force_active on
extern "C" {
extern int fn_801932AC(void*, float);

int fn_80197A0C(void* obj, unsigned int index) {
    unsigned short* arr = *(unsigned short**)((char*)obj + 0x14);
    unsigned short val = arr[index];
    if ((val & 0x4000) || (val & 0x8000))
        return 1;
    return fn_801932AC((char*)obj + 0x2C, *(float*)((char*)obj + 0x18));
}
}
