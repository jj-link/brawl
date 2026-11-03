#pragma force_active on
struct Storage { void* primary; void* secondary; };
struct Registration { void* next; void* object; void* destructor; };
class View {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_112_bss_25C;
extern Storage lbl_112_bss_260;
extern Registration lbl_112_bss_1E8;
extern unsigned char lbl_112_data_2150[], lbl_112_data_2124[];
extern unsigned char lbl_112_data_20BC[], lbl_112_data_72A4[];
void* fn_112_112F0(void*, short);
void __register_global_object(void*, void*, void*);
void fn_112_116E0(void*) {
    if (lbl_112_bss_25C == 0) {
        lbl_112_bss_260.primary = lbl_112_data_2150;
        lbl_112_bss_260.secondary = lbl_112_data_2124;
        lbl_112_bss_260.primary = lbl_112_data_20BC;
        lbl_112_bss_260.secondary = lbl_112_data_20BC + 0x10;
        lbl_112_bss_260.primary = lbl_112_data_72A4;
        lbl_112_bss_260.secondary = lbl_112_data_72A4 + 0x10;
        __register_global_object(&lbl_112_bss_260, reinterpret_cast<void*>(fn_112_112F0), &lbl_112_bss_1E8);
        lbl_112_bss_25C = 1;
    }
    reinterpret_cast<View*>(&lbl_112_bss_260)->dispatch();
}
}