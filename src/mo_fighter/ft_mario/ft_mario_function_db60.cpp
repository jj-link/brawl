#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_98[];
void* fn_91_DBA8(void* object, int kind);

void* fn_91_DB60(void* object) {
    fn_91_DBA8(object, 0);
    *(unsigned char**)(static_cast<unsigned char*>(object) + 8) = lbl_91_data_98;
    *(unsigned char**)static_cast<unsigned char*>(object) = lbl_91_data_98 + 8;
    return object;
}
}
