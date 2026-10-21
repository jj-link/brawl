#pragma force_active on
extern "C" unsigned int fn_80111CB0(void*, void*);

extern "C" unsigned int fn_80134C54(void* arg0, unsigned int* arg1) {
    unsigned int sp8;
    sp8 = *arg1;
    return fn_80111CB0(&sp8, (void*)((unsigned char*)arg0 + 0x164));
}
