#pragma force_active on
extern "C" int fn_8015B228(void* p);

extern "C" int fn_8015A33C(char* self) {
    if (*(unsigned int*)(self + 0x24) >> 31) {
        return fn_8015B228(*(void**)(self + 0x8));
    }
    return 1;
}
