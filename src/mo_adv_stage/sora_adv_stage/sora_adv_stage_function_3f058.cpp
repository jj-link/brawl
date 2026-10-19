#pragma force_active on
extern "C" {
int fn_40_3F058(char* r3, int r4, int r5)
{
    int base = *(int*)(r3 + r4 * 0xac + 0xe8);
    return *(int*)(r3 + (r5 + base + 0xd) * 4 + 0x710);
}
}
