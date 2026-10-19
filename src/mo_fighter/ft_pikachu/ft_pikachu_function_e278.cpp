#pragma force_active on
extern "C" {
extern const char lbl_98_data_28[];
void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
}

extern "C" void* fn_98_E278(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 7);
    const char* vt = lbl_98_data_28;
    *reinterpret_cast<const char**>(static_cast<char*>(self) + 8) = vt;
    *reinterpret_cast<const char**>(self) = vt + 8;
    return self;
}
