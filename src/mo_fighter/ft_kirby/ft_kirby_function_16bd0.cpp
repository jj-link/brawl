#pragma force_active on
extern "C" unsigned char lbl_96_data_B710[0x40];

struct ModuleInfo {
    unsigned char *data;
};

extern "C" void fn_96_16BD0(ModuleInfo *module)
{
    module->data = lbl_96_data_B710;
}
