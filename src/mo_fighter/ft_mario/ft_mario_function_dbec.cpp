#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_28[];
void* fn_91_DBA8(void* object, int kind);

void* fn_91_DBEC(void* object) {
    fn_91_DBA8(object, 0x36);
    *(unsigned char**)(static_cast<unsigned char*>(object) + 8) = lbl_91_data_28;
    *(unsigned char**)static_cast<unsigned char*>(object) = lbl_91_data_28 + 8;
    return object;
}
}
