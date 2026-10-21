#pragma force_active on
struct ColorBytes { unsigned char r, g, b, a; };
extern struct ColorBytes lbl_8059FF8C;
extern char lbl_804207F8[];
extern char lbl_80494880[];
extern void *lbl_8059FF88;
extern "C" void __dt__Q34nw4r2ut5ColorFv(void *);
extern "C" void __register_global_object(void *, void (*)(void *), void *, void *);

extern "C" void fn_80011C30(void) {
    unsigned char c = 0x80;
    unsigned char *obj = (unsigned char *)&lbl_8059FF8C;
    lbl_8059FF88 = lbl_804207F8;
    obj[0] = c;
    obj[1] = c;
    obj[2] = c;
    obj[3] = 0x60;
    __register_global_object(&lbl_8059FF8C, __dt__Q34nw4r2ut5ColorFv, lbl_80494880, obj);
}

__declspec(section ".ctors") extern void* const fn_80011C30_ctor = (void*)fn_80011C30;
