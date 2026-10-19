#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_54198[];
void fn_27_25CEA4(void* self, int arg);
}

struct sora_melee_obj_t {
    void* vtbl;
    u8 pad4[0xC];
    u32 unk10;
    u8 unk14;
};

extern "C" void* fn_27_25D26C(void* self) {
    sora_melee_obj_t* obj = static_cast<sora_melee_obj_t*>(self);
    fn_27_25CEA4(self, 1);
    obj->unk10 = 0;
    obj->vtbl = lbl_27_data_54198;
    obj->unk14 = 0;
    return self;
}
