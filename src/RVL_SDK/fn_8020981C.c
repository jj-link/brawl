#pragma force_active on
typedef unsigned short u16;

int fn_8020981C(void) {
    return ((*(u16*)0xCC005000) >> 15) & 1;
}
