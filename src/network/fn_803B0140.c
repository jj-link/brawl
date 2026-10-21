#pragma force_active on
extern int fn_803AFA84(int, void*);

int fn_803B0140(void *arg0) {
    int temp = fn_803AFA84((int)arg0, *(void**)((char*)arg0 + 0x15F4));
    return temp & ((-temp | temp) >> 31);
}
