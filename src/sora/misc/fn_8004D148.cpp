#pragma force_active on
extern "C" int fn_8004D148(void* p) {
    unsigned short* rec = (unsigned short*)*(void**)((char*)p + 0x28);
    int count = 0;
    for (int i = 0; i < 120; i++) {
        if (rec[0x70]) count++;
        rec += 0x92;
    }
    return count;
}