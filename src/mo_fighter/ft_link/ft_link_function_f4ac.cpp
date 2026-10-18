#pragma force_active on
extern "C" {
struct Subscriber {
    void *vptr;
};
}

extern "C" void *lbl_93_data_8150[];

extern "C" Subscriber *fn_93_F4AC(Subscriber *sub)
{
    sub->vptr = lbl_93_data_8150;
    return sub;
}
