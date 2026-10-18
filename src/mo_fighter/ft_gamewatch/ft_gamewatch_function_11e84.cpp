#pragma force_active on
extern "C" unsigned char lbl_107_data_8E70[];

struct Wrapper {
    void *vptr;
};

extern "C" void fn_107_11E84(Wrapper *object)
{
    object->vptr = lbl_107_data_8E70;
}
