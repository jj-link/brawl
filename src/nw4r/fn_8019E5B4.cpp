#pragma force_active on
extern unsigned char lbl_804A7F40[];
extern "C" void fn_801EC41C(const void*, void*);
extern "C" void fn_801EC1B8(const void*, const void*, void*);
extern "C" void fn_801EC184(const void*, void*);

struct CameraBank { unsigned char pad[0x34]; unsigned char cameras[32][0x30]; };

static inline void* slot(int id, int off) {
    if (id < 32 && id >= 0)
        return lbl_804A7F40 + id * 0x30 + off;
    return 0;
}

extern "C" void fn_8019E5B4(void* arg0, signed char arg1) {
    if (arg0 != 0) {
        if (arg1 >= 0 && arg1 < 32) {
            unsigned char* p;
            if (arg1 < 32 && arg1 >= 0) {
                p = ((CameraBank*)lbl_804A7F40)->cameras[arg1];
            } else {
                p = 0;
            }
            if (!(*(unsigned short*)lbl_804A7F40 & 1)) {
                fn_801EC41C(lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0x34, lbl_804A7F40 + 4);
                *(unsigned short*)lbl_804A7F40 |= 1;
            }
            fn_801EC1B8(p, lbl_804A7F40 + 4, arg0);
            fn_801EC1B8(slot(arg1, 0xE34), arg0, arg0);
        } else {
            fn_801EC184(lbl_804A7F40 + *(unsigned short*)(lbl_804A7F40 + 2) * 0x30 + 0xE34, arg0);
        }
    }
}
