#pragma force_active on
extern "C" const char lbl_27_data_4BEC0[];
extern "C" const char lbl_27_data_4BD80[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_23680C(void*, void*);

extern "C" {
void fn_27_233C70(void* self, void* arg) {
    void* p = __dynamic_cast(*(void**)((char*)self + 0x18), 4, lbl_27_data_4BD80, lbl_27_data_4BEC0, 0);
    if (p) {
        void* q = __dynamic_cast(*(void**)((char*)self + 0x18), 4, lbl_27_data_4BD80, lbl_27_data_4BEC0, 0);
        fn_27_23680C(q, arg);
    }
}
}
