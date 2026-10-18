#pragma force_active on
extern "C" {

extern unsigned char lbl_96_data_E570[];

extern void fn_96_2DA94(void *object)
{
    *reinterpret_cast<unsigned char **>(object) = lbl_96_data_E570;
}

}
