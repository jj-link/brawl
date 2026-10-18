#pragma force_active on
extern "C" unsigned char lbl_121_data_8670[0x40];

namespace {
struct ToonLinkEmpty {
    void *vptr;
};
}

extern "C" void fn_121_110C0(ToonLinkEmpty *object)
{
    object->vptr = lbl_121_data_8670;
}
