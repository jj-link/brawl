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
extern signed char lbl_113_bss_178;
extern Storage lbl_113_bss_17C;
extern Registration lbl_113_bss_300;
extern unsigned char lbl_113_data_2314[], lbl_113_data_22E8[];
extern unsigned char lbl_113_data_2280[], lbl_113_data_7E2C[];
void* fn_113_1BE0C(void*, short);
void __register_global_object(void*, void*, void*);
void fn_113_2D578(void*) {
    if (lbl_113_bss_178 == 0) {
        lbl_113_bss_17C.primary = lbl_113_data_2314;
        lbl_113_bss_17C.secondary = lbl_113_data_22E8;
        lbl_113_bss_17C.primary = lbl_113_data_2280;
        lbl_113_bss_17C.secondary = lbl_113_data_2280 + 0x10;
        lbl_113_bss_17C.primary = lbl_113_data_7E2C;
        lbl_113_bss_17C.secondary = lbl_113_data_7E2C + 0x10;
        __register_global_object(&lbl_113_bss_17C, reinterpret_cast<void*>(fn_113_1BE0C), &lbl_113_bss_300);
        lbl_113_bss_178 = 1;
    }
    reinterpret_cast<View*>(&lbl_113_bss_17C)->dispatch();
}
}