#pragma force_active on
extern "C" {
extern const char lbl_10_rodata_688[8];
int fn_10_14414(void* a, const char* name, int flag, int b, int c);
}

extern "C" int fn_10_14368(void* a, int b, int c)
{
    return fn_10_14414(a, lbl_10_rodata_688, 1, b, c);
}
