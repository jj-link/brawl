#pragma force_active on
struct Accesser { char prefix[8]; void* owner; };

extern "C" {
extern const char lbl_95_data_5F8[];
extern const char lbl_95_data_36D8[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void fn_27_16A788(void*, void*, void*);
void fn_95_AE3C(void*);

void fn_95_F268(void* a, void* b, void* c) {
    fn_27_16A788(a, b, c);
    if ((int)c != 0x1a && (int)c != 0x1b && (int)c != 0x1d && (int)c != 0x1f && (int)c != 0x20) {
        Accesser* acc = (Accesser*)b;
        void* owner = __dynamic_cast(acc->owner, 0x3c, lbl_95_data_5F8, lbl_95_data_36D8, short(1));
        fn_95_AE3C(owner);
    }
}
}
