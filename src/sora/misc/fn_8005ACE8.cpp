#pragma force_active on
extern "C" char lbl_8040AA68[];

extern "C" int fn_8005ACE8(void* unused, int* arg1)
{
    return *arg1 == (int)lbl_8040AA68;
}
