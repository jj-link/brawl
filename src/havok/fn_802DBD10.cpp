#pragma force_active on

struct fn_802D95E4_Obj {
    void* unk0;
    void* unk4;
    unsigned int unk8;
};

extern "C" {
extern fn_802D95E4_Obj lbl_80487AE4;
void fn_802D95E4(fn_802D95E4_Obj* self, unsigned int v);

void* fn_802DBD10(void* self) {
    char* p = (char*)self;
    *(unsigned short*)(p + 6) = 1;
    unsigned int v = *(unsigned int*)(p + 0x14);
    *(void**)p = &lbl_80487AE4;
    fn_802D95E4((fn_802D95E4_Obj*)(p + 0xC), v);
    fn_802D95E4((fn_802D95E4_Obj*)(p + 0xC), (unsigned int)self);
    return self;
}
}
