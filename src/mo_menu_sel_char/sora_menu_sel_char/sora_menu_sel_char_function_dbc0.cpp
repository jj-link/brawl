#pragma force_active on
extern "C" int fn_10_DA54(void*, int);
extern "C" void fn_800B68F0(void*, int, char*, char*);
extern "C" char lbl_10_data_5B8[];
extern "C" char lbl_10_data_5C0[];

struct MenuStruct {
    unsigned char padding[0x13C];
    void* data[252];
};

extern "C" int fn_10_DBC0(MenuStruct* self, int kind, int arg3) {
    int index = fn_10_DA54(self, arg3);
    if (index < 0) {
        return 0;
    }
    fn_800B68F0(self->data[index + 0xC], kind, lbl_10_data_5B8, lbl_10_data_5C0);
    return 1;
}
