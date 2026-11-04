#pragma force_active on
struct Storage { void* primary; void* secondary; };
struct Registration { void* next; void* object; void* destructor; };
class View {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual int dispatch();
};
extern "C" {
extern signed char lbl_105_bss_38C;
extern Storage lbl_105_bss_390;
extern Registration lbl_105_bss_440;
extern unsigned char lbl_105_data_31B4[], lbl_105_data_3188[];
extern unsigned char lbl_105_data_3120[], lbl_105_data_8B7C[];
void* fn_105_18384(void*, short);
void __register_global_object(void*, void*, void*);
int fn_105_1EA6C(void*) {
    if (lbl_105_bss_38C == 0) {
        lbl_105_bss_390.primary = lbl_105_data_31B4;
        lbl_105_bss_390.secondary = lbl_105_data_3188;
        lbl_105_bss_390.primary = lbl_105_data_3120;
        lbl_105_bss_390.secondary = lbl_105_data_3120 + 0x10;
        lbl_105_bss_390.primary = lbl_105_data_8B7C;
        lbl_105_bss_390.secondary = lbl_105_data_8B7C + 0x10;
        __register_global_object(&lbl_105_bss_390, reinterpret_cast<void*>(fn_105_18384), &lbl_105_bss_440);
        lbl_105_bss_38C = 1;
    }
    return reinterpret_cast<View*>(&lbl_105_bss_390)->dispatch();
}
}