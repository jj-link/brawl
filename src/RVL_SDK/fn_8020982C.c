#pragma force_active on
typedef unsigned short u16;

int fn_8020982C(void) {
    return (*(u16*)0xCC005004 >> 15) & 1;
}
