#pragma force_active on
extern "C" {
struct ftExtendParamAccesser;
void* __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern char lbl_94_data_4144[];
}

struct Fn94Obj {
    void* vt;
    void* unk4;
    void* p8;
};

extern "C" void* fn_94_EB38(void* self) {
    Fn94Obj* o = (Fn94Obj*)self;
    __ct__21ftExtendParamAccesserF6ftKind(self, 3);
    o->p8 = (void*)lbl_94_data_4144;
    o->vt = (void*)(lbl_94_data_4144 + 8);
    return self;
}
