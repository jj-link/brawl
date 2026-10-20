#pragma force_active on
extern "C" {
int fn_27_2C1674(void* p);

int fn_27_2A25E8(char* self) {
    int t = *(int*)(self + 0x50);
    if ((unsigned int)(t - 2) <= 1) {
        return fn_27_2C1674(*(void**)(self + 0x14b8));
    }
    return 1;
}
}
