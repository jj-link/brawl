#pragma force_active on
#pragma opt_propagation off

extern "C" {
extern char lbl_5_data_660[];
void fn_6_1134(void*);
void fn_800FABEC(void*);
void fn_800FAC58(void*, const char*, int, int);
void loadMenuSound__6muMenuFv();
}

struct Menu {
    char pad[0x1AC];
    char* data;
};

extern "C" void fn_5_12500(Menu* self) {
    char* strings = lbl_5_data_660;
    fn_6_1134(self);
    char* resource = self->data;
    const char* path = strings + 0x1C;
    fn_800FABEC(resource + 0x14);
    *(int*)resource = 0;
    resource[0x2C] = 0;
    fn_800FAC58(resource + 0x14, path, 0x2B, 0);
    char* resource2 = self->data + 0x9C;
    const char* path2 = strings + 0x40;
    fn_800FABEC(resource2 + 0x14);
    *(int*)resource2 = 0;
    resource2[0x2C] = 0;
    fn_800FAC58(resource2 + 0x14, path2, 0x2B, 0);
    fn_800FAC58(self->data + 0x1C80, strings + 0x58, 0x2B, 0);
    fn_800FAC58(self->data + 0x1C98, strings + 0x74, 0x2B, 0);
    fn_800FAC58(self->data + 0x1D0C, strings + 0x90, 0x2B, 0);
    fn_800FAC58(self->data + 0x1D24, strings + 0xA8, 0x2B, 0);
    loadMenuSound__6muMenuFv();
}
