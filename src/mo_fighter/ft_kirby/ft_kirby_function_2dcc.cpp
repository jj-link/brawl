#pragma force_active on

extern "C" {
extern char lbl_96_data_C390[];

void fn_96_1FD0(void*, unsigned char);
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);

void* fn_96_2DCC(void* self, void*, void*, unsigned int kind, unsigned int value)
{
    fn_96_1FD0(self, 0);
    *(unsigned int*)((char*)self + 8) = value;
    *(void**)self = lbl_96_data_C390;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        (char*)self + 0xC, 0, self, (unsigned char)kind);
    return self;
}
}
