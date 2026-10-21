#pragma force_active on
extern "C" void fn_800ADCF0(char* arg) {
    char* p = arg;
    unsigned int i = 0;
    while (i < (unsigned int)*(int*)(arg + 0x2F04)) {
        *(int*)(p + 0x7E4) = *(int*)(p + 0x2F08);
        i++;
        p += 4;
    }
}
