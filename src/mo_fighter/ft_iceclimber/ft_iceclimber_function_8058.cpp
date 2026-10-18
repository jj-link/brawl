#pragma force_active on
extern char lbl_105_data_391C[];

extern "C" {
void fn_105_8058(void *obj, char val)
{
    *(void **)obj = lbl_105_data_391C;
    ((char *)obj)[4] = val;
}
}
