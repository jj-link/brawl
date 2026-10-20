#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_36908C(void*, void*, void*);
extern char lbl_27_data_C938[];
extern char lbl_27_data_92028[];

extern "C" void fn_27_369028(void* self, void* obj, void* arg) {
    void* p = __dynamic_cast(obj, 0, lbl_27_data_92028, lbl_27_data_C938, 0);
    fn_27_36908C(self, p, arg);
}
