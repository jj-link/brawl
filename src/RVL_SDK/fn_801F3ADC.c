#pragma force_active on
extern int* __GXData;

void GXSetNumIndStages(unsigned char num) {
    int* p = __GXData;
    p[0x95] = __rlwimi(p[0x95], num, 16, 13, 15);
    p[0x17F] |= 6;
}
