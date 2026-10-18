#pragma force_active on
extern "C" {
extern char lbl_97_data_2FFC[];

void fn_97_8060(void *object, char isNull)
{
    char *tbl = lbl_97_data_2FFC;
    *(void **)object = (void *)tbl;
    *(char *)((char *)object + 4) = isNull;
}
}
