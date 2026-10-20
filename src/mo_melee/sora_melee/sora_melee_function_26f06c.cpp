#pragma force_active on
extern "C" void fn_27_5C7AC(void* self);
extern "C" char lbl_27_data_56F38[];

extern "C" void* fn_27_26F06C(void* self) {
    char* p = (char*)self;
    fn_27_5C7AC(self);
    char* base = lbl_27_data_56F38;
    *(char**)(p + 0x8) = base;
    *(char**)(p + 0x0) = base + 0x8;
    *(char**)(p + 0xC) = base + 0xD8;
    *(char**)(p + 0x18) = base + 0xF0;
    *(char**)(p + 0x24) = base + 0x100;
    *(char**)(p + 0x30) = base + 0x10C;
    return self;
}
