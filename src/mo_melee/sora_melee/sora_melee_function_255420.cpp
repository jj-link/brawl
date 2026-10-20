#pragma force_active on
extern "C" {
extern const char lbl_27_data_52E38[];
extern char lbl_27_data_52EF8[];

void* fn_27_241E30(void* self, const char* name);

void* fn_27_255420(void* self) {
    fn_27_241E30(self, lbl_27_data_52E38);
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x3C) = lbl_27_data_52EF8;
    return self;
}
}
