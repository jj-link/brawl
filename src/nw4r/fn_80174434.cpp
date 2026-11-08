#pragma force_active on

struct GlobalObj {
    void* vtable;
};

extern "C" {

extern unsigned int lbl_804A3E90[0x15E];
extern signed char lbl_805A04F0;
extern signed char lbl_805A04F1;
extern signed char lbl_805A04F2;
extern signed char lbl_805A04F3;
extern signed char lbl_805A04F4;
extern signed char lbl_805A04F5;
extern signed char lbl_805A04F6;

void fn_80176444(void*);
void fn_801783F0(void*);
void fn_8017A4A4(void*);
void fn_8017AC30(void*);
void fn_8017B10C(void*);
void fn_8017B400(void*);
void fn_8017E24C(void*);

void* fn_80174618(void*, int);
void* fn_80174658(void*, int);
void* fn_80174698(void*, int);
void* fn_801746D8(void*, int);
void* fn_80174718(void*, int);
void* fn_80174758(void*, int);
void* fn_80174798(void*);

void* __register_global_object(void*, void*, void*);

#pragma push
#pragma opt_propagation off
void* fn_80174434(void* unused, unsigned int arg) {
    char* base = (char*)lbl_804A3E90;
    GlobalObj* obj = (GlobalObj*)lbl_804A3E90;
    void* (GlobalObj::*ptr0) = &GlobalObj::vtable;

    if (lbl_805A04F0 == 0) {
        fn_80176444(base + 0xC);
        __register_global_object(base + 0xC, (void*)fn_80174618, &(obj->*ptr0));
        lbl_805A04F0 = 1;
    }
    if (lbl_805A04F1 == 0) {
        fn_801783F0(base + 0xD4);
        __register_global_object(base + 0xD4, (void*)fn_80174658, base + 0xC8);
        lbl_805A04F1 = 1;
    }
    if (lbl_805A04F2 == 0) {
        fn_8017A4A4(base + 0x19C);
        __register_global_object(base + 0x19C, (void*)fn_80174698, base + 0x190);
        lbl_805A04F2 = 1;
    }
    if (lbl_805A04F3 == 0) {
        fn_8017AC30(base + 0x264);
        __register_global_object(base + 0x264, (void*)fn_801746D8, base + 0x258);
        lbl_805A04F3 = 1;
    }
    if (lbl_805A04F4 == 0) {
        fn_8017B10C(base + 0x32C);
        __register_global_object(base + 0x32C, (void*)fn_80174718, base + 0x320);
        lbl_805A04F4 = 1;
    }
    if (lbl_805A04F5 == 0) {
        fn_8017B400(base + 0x3F4);
        __register_global_object(base + 0x3F4, (void*)fn_80174758, base + 0x3E8);
        lbl_805A04F5 = 1;
    }
    if (lbl_805A04F6 == 0) {
        fn_8017E24C(base + 0x4BC);
        __register_global_object(base + 0x4BC, (void*)fn_80174798, base + 0x4B0);
        lbl_805A04F6 = 1;
    }

    switch (arg) {
    case 3:
        return base + 0xC;
    case 4:
        return base + 0xD4;
    case 2:
        return base + 0x19C;
    case 1:
        return base + 0x264;
    case 0:
        return base + 0x32C;
    case 5:
        return base + 0x3F4;
    case 6:
        return base + 0x4BC;
    default:
        return base + 0xC;
    }
}
#pragma pop

}
