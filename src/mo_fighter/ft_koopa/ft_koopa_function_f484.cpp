#pragma force_active on
extern "C" unsigned char lbl_102_data_6284[0x40];

namespace {

struct FtKoopaConsts {
    const unsigned char *raw;
};

}

extern "C" void fn_102_F484(FtKoopaConsts *object)
{
    object->raw = &lbl_102_data_6284[0];
}