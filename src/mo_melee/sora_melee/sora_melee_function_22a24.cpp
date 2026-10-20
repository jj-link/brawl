#pragma force_active on
extern "C" unsigned char lbl_27_data_24C0[];

extern "C" void fn_27_22A24(void *self, void *arg)
{
    *(void **)((char *)self + 4) = arg;
    *(void **)self = lbl_27_data_24C0;
}
