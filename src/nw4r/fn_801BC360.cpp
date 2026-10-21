#pragma force_active on
extern "C" {
extern char lbl_804665B8[];

void fn_801BC3A4(void* self, void* data);

void* fn_801BC360(void* self) {
    *(int*)(static_cast<char*>(self) + 4) = -1;
    *static_cast<void**>(self) = &lbl_804665B8;
    fn_801BC3A4(self, &lbl_804665B8);
    return self;
}
}
