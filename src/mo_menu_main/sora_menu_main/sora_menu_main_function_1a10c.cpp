#pragma force_active on
extern "C" int fn_2_1A15C(void*);

extern "C" int fn_2_1A10C(void* self) {
    int result = 0;
    switch (*(int*)((char*)self + 0x664)) {
    case 0:
        result = fn_2_1A15C(self);
        break;
    case 1:
        result = 3;
        break;
    default:
        break;
    }
    return result;
}
