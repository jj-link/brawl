#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_108[];
void* __ct__21ftExtendParamAccesserF6ftKind(void*, int);

void* fn_91_DBA8(void* object, int kind) {
    __ct__21ftExtendParamAccesserF6ftKind(object, kind);
    *(unsigned char**)(static_cast<unsigned char*>(object) + 8) = lbl_91_data_108;
    *(unsigned char**)static_cast<unsigned char*>(object) = lbl_91_data_108 + 8;
    return object;
}
}
