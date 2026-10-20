#pragma force_active on
extern "C" {
void fn_20_2CF4(void*);
extern char lbl_20_data_2F8[];

void* fn_20_2FBC(void* self) {
    char* base = lbl_20_data_2F8;
    char* p = (char*)self;
    fn_20_2CF4(self);
    *(char**)(p + 0x00) = base;
    *(char**)(p + 0x18) = base + 0x18;
    *(char**)(p + 0x1C) = base + 0x34;
    *(int*)(p + 0x24) = 0;
    *(int*)(p + 0x28) = 0;
    *(int*)(p + 0x2C) = 0;
    *(int*)(p + 0x40) = 3;
    *(int*)(p + 0x70) = 0;
    return self;
}
}
