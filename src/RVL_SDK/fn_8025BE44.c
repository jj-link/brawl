#pragma force_active on
extern int fn_803F6150(const void*, const void*, unsigned long);

unsigned char fn_8025BE44(void *arg0, void *arg1) {
    unsigned int temp_r5;

    temp_r5 = *(unsigned short *)arg0;
    if (temp_r5 != (*(unsigned short *)((char *)arg1 + 6) & 0xFFF)) {
        return 0;
    }
    if (temp_r5 == 2) {
        return (unsigned char)(*(unsigned short *)((char *)arg0 + 4) == *(unsigned short *)((char *)arg1 + 8));
    }
    if (temp_r5 == 4) {
        return (unsigned char)(*(unsigned int *)((char *)arg0 + 4) == *(unsigned int *)((char *)arg1 + 8));
    }
    return (unsigned char)(fn_803F6150((char *)arg0 + 4, (char *)arg1 + 8, 0x10) == 0);
}
