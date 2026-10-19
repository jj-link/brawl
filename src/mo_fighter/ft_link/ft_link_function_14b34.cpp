#pragma force_active on
extern "C" {
extern const char lbl_93_data_7B28[];
extern const char lbl_93_data_3BF8[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA698(void*, int, int, int);

void fn_93_14B34(void* unused, void* accesser) {
    void* object = *(void**)((char*)accesser + 8);
    void* casted = __dynamic_cast(object, 0x3c, lbl_93_data_7B28, lbl_93_data_3BF8, short(1));
    fn_27_1DA698(casted, -1, -1, -1);
}
}
