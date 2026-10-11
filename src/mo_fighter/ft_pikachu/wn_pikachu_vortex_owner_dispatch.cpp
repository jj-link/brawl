struct VortexDispatchAccesser { char prefix[8]; void* owner; };
extern "C" {
extern const char lbl_98_data_6D5C[];
extern const char lbl_98_data_2F88[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void fn_98_180A4(void*);

void fn_98_192B4(void*, VortexDispatchAccesser* accesser) {
    void* owner = __dynamic_cast(accesser->owner, 0x3c, lbl_98_data_6D5C, lbl_98_data_2F88, short(1));
    fn_98_180A4(owner);
}
}
