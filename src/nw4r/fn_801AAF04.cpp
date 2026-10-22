#pragma force_active on
extern "C" {

void fn_801EC184(int, char*);
void fn_801EC158(char*);

int fn_801AAF04(char* arg0, unsigned arg1, int arg2) {
    if (arg1 < 3) {
        if (arg2 != 0) {
            if (arg1 == 0) {
                *(int*)(arg0 + 0xCC) &= 0x7FFFFFFF;
            }
            fn_801EC184(arg2, arg0 + arg1 * 0x30 + 0xC);
        } else {
            if (arg1 == 0) {
                *(int*)(arg0 + 0xCC) |= 0x80000000;
            }
            fn_801EC158(arg0 + arg1 * 0x30 + 0xC);
        }
        return 1;
    }
    return 0;
}

}
