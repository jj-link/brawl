#pragma force_active on

extern "C" {
extern signed char lbl_27_bss_7B9C;
extern signed char lbl_27_bss_7B94;
extern void* lbl_27_bss_7BA0;
extern void* lbl_27_bss_7B98;
extern char lbl_27_bss_7B7C[];
extern char lbl_27_bss_7B70[];
extern char lbl_27_data_11B38[];
extern char lbl_27_data_119D8[];
extern char __vt__25soControllerModuleLinkRef[];

void fn_27_82854(void*, short);
void fn_27_82814(void*, short);
void* __register_global_object(void*, void*, void*);
void fn_27_58264(void*, short, void*, void*);
}

struct ControllerLinkRef {
    void* vt0;
    void* vt1;
    char pad[0x10];
    void* owner;
    int pad2;
    int pad3;
};

extern "C" ControllerLinkRef* fn_27_314FE8(
    ControllerLinkRef* self, int a1, short a2
) {
    if (lbl_27_bss_7B9C == 0) {
        lbl_27_bss_7BA0 = 0;
        lbl_27_bss_7BA0 = lbl_27_data_11B38;
        __register_global_object(&lbl_27_bss_7BA0, (void*)fn_27_82854, lbl_27_bss_7B7C);
        lbl_27_bss_7B9C = 1;
    }

    void* base = &lbl_27_bss_7BA0;

    if (lbl_27_bss_7B94 == 0) {
        lbl_27_bss_7B98 = 0;
        lbl_27_bss_7B98 = lbl_27_data_119D8;
        __register_global_object(&lbl_27_bss_7B98, (void*)fn_27_82814, lbl_27_bss_7B70);
        lbl_27_bss_7B94 = 1;
    }

    char* b = (char*)self + 4;
    fn_27_58264(b, a2, base, &lbl_27_bss_7B98);

    char* vt = __vt__25soControllerModuleLinkRef;
    ((int*)b)[5] = a1;
    ((void**)b)[0] = vt;
    ((void**)(b + 4))[0] = (void*)(vt + 0x110);
    ((int*)b)[6] = 0;

    return self;
}
