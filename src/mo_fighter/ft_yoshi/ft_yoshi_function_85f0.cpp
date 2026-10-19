#pragma force_active on
extern "C" void fn_95_85F0(void *arg0, void *arg1)
{
    extern unsigned char lbl_27_data_8E80[];

    unsigned char *out = (unsigned char *)arg0;
    *(void **)(out + 0x00) = lbl_27_data_8E80;
    *(void **)(out + 0x04) = arg1;
    *(int *)(out + 0x08) = 0;

    int stack_zero = 0;
    *(int *)(&stack_zero) = 0;

    *(int *)(out + 0x0C) = -1;
    *(int *)(out + 0x10) = -1;
    *(int *)(out + 0x14) = 0;
}
