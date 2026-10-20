#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern "C" const char lbl_27_data_4BCF8[];
extern "C" const char __RTTI__10gfCallBack[];

extern "C" void fn_27_233FCC(char* self, void* cb) {
    void** head = *(void***)(self + 0x28);
    if (head != 0) {
        void** p = head;
        while (*p != 0) {
            p = (void**)*p;
        }
        *p = cb;
    } else {
        *(void**)(self + 0x28) = __dynamic_cast(cb, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
    }
}
