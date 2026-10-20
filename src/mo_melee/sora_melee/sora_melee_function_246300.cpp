#pragma force_active on
extern "C" {
extern const char lbl_27_data_4E790[];
extern const char lbl_27_data_4E7A8[];

void* fn_27_241E30(void* self, const char* name);

void* fn_27_246300(void* self) {
    fn_27_241E30(self, lbl_27_data_4E790);
    *(const void**)((char*)self + 0x3C) = lbl_27_data_4E7A8;
    return self;
}
}
