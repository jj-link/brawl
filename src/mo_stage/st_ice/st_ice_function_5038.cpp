#pragma force_active on

typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" {

typedef struct IceObj {
    char c;
    char pad1;
    char pad2;
    char pad3;
    void* p;
} IceObj;

extern IceObj lbl_62_bss_50;
extern char lbl_62_bss_4C;
extern DestructorChain lbl_62_bss_28;
extern unsigned char lbl_62_data_11F0[0x38];
extern unsigned char lbl_62_data_1198[0x38];

void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
void* fn_62_50FC(void* p, int n);

void* fn_62_5038(void) {
    if (lbl_62_bss_4C == 0) {
        IceObj* o = &lbl_62_bss_50;
        o->p = (void*)lbl_62_data_11F0;
        o->c = 1;
        o->p = (void*)lbl_62_data_1198;
        __register_global_object((void*)o, (void*)fn_62_50FC, &lbl_62_bss_28);
        lbl_62_bss_4C = 1;
    }
    return &lbl_62_bss_50;
}

}
