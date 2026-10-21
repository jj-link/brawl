#pragma force_active on
extern "C" int fn_800AC9A4(void* p);

extern "C" int fn_8009C830(void* self) {
    int state = *(int*)((char*)self + 0x40);
    if (state == 2 || state == 12) {
        return 0;
    }
    if (state == 13) {
        return fn_800AC9A4(*(void**)((char*)self + 0x80));
    }
    return 1;
}
