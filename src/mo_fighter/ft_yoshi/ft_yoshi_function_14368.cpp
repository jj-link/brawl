#pragma force_active on
extern "C" unsigned char lbl_95_data_8548[];

struct YoshiVTable {
    unsigned long entries[16];
};

extern "C" void fn_95_14368(YoshiVTable **object)
{
    YoshiVTable *tmp;

    tmp = (YoshiVTable *)&lbl_95_data_8548[0];
    *object = tmp;
}
