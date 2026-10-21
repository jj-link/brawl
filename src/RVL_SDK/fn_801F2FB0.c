#pragma force_active on
typedef int (*GXFn)(void);

extern unsigned char* const __GXData;
void fn_801F2E4C(int a, int b, int c);

void fn_801F2FB0(int arg0, int arg1) {
    GXFn fn = *(GXFn*)(__GXData + 0x518);
    fn_801F2E4C(arg0, fn(), arg1);
}
