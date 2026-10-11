struct LuigiParameterAccesser {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_99_data_8[];
void __ct__21ftExtendParamAccesserF6ftKind(LuigiParameterAccesser*, int);
}

extern "C" LuigiParameterAccesser* fn_99_B8E4(LuigiParameterAccesser* accesser) {
    __ct__21ftExtendParamAccesserF6ftKind(accesser, 8);
    accesser->typeInfo = lbl_99_data_8;
    accesser->vtable = lbl_99_data_8 + 8;
    return accesser;
}
