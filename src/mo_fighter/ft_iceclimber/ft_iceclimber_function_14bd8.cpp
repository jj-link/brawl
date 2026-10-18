#pragma force_active on
extern "C" unsigned char lbl_105_data_81D0[];

namespace {
struct ModuleInfo {
    void *vtable;
    unsigned char reserved[0x3C];
};
}

// Module info pointer setup for the Ice Climbers module: store the address of
// the 0x40-byte module info block (lbl_105_data_81D0) into the module's field 0.
extern "C" void fn_105_14BD8(ModuleInfo *module)
{
    module->vtable = lbl_105_data_81D0;
}