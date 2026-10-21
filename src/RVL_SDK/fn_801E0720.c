#pragma force_active on

int fn_801E0720(int* arg) {
    int val = arg[0xB3];
    return (unsigned int)((-val) & ~val) >> 31;
}
