#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" char lbl_105_data_C4[];

extern "C" {
void* fn_105_12CDC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0xf);
    char* p = lbl_105_data_C4;
    ((char**)self)[2] = p;
    ((char**)self)[0] = p + 8;
    return self;
}
}
