#pragma force_active on
extern "C" char lbl_113_data_2A0C[];
extern "C" char lbl_113_data_AD50[];

struct FtPikminObj {
    void *vtbl;
    unsigned char flag;
    unsigned int w8;
    unsigned int wc;
};

extern "C" void fn_113_24AD0(FtPikminObj *dst, const FtPikminObj *src)
{
    dst->vtbl = lbl_113_data_2A0C;
    dst->flag = src->flag;
    dst->vtbl = lbl_113_data_AD50;
    dst->w8 = src->w8;
    dst->wc = src->wc;
}
