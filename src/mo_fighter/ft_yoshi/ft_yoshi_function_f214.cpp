#pragma force_active on
struct Accesser { char prefix[8]; void* owner; };

extern "C" {
extern const char lbl_95_data_5F8[];
extern const char lbl_95_data_36D8[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void fn_27_16A660(void*, void*);
void fn_95_ACEC(void*);

void fn_95_F214(void* a, Accesser* b) {
    fn_27_16A660(a, b);
    void* owner = __dynamic_cast(b->owner, 0x3c, lbl_95_data_5F8, lbl_95_data_36D8, short(1));
    fn_95_ACEC(owner);
}
}
