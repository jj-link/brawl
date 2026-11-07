#pragma force_active on
#pragma push
#pragma opt_propagation off
extern "C" void __register_global_object(void*, void* (*)(void*, int), void*);
extern "C" void* fn_27_3C79A8(void*, int);
extern "C" void* fn_27_3C79E8(void*, int);
extern "C" void* fn_27_3C7A28(void*, int);
extern "C" void* fn_27_3C7A68(void*, int);
extern "C" void* fn_27_3C7AA8(void*, int);
extern "C" void* fn_27_3C7AE8(void*, int);
extern "C" void* fn_27_3C7B28(void*, int);
extern "C" void* fn_27_3C7B68(void*, int);

struct Entry {
    void* ptr;
    int unk4;
    int unk8;
    void* data;
};

extern "C" Entry lbl_27_bss_8BF0[];
extern "C" unsigned char lbl_27_data_A2010[];

extern "C" void fn_27_3C7BA8() {
    void* (Entry::*firstPtr) = &Entry::ptr;

    lbl_27_bss_8BF0[0].data = (void*)(lbl_27_data_A2010 + 0xD20);
    __register_global_object(&lbl_27_bss_8BF0[0].data, fn_27_3C7B68, &(lbl_27_bss_8BF0[0].*firstPtr));

    lbl_27_bss_8BF0[1].data = (void*)(lbl_27_data_A2010 + 0xCA0);
    __register_global_object(&lbl_27_bss_8BF0[1].data, fn_27_3C7B28, &lbl_27_bss_8BF0[1].ptr);

    lbl_27_bss_8BF0[2].data = (void*)(lbl_27_data_A2010 + 0xC20);
    __register_global_object(&lbl_27_bss_8BF0[2].data, fn_27_3C7AE8, &lbl_27_bss_8BF0[2].ptr);

    lbl_27_bss_8BF0[3].data = (void*)(lbl_27_data_A2010 + 0xBA0);
    __register_global_object(&lbl_27_bss_8BF0[3].data, fn_27_3C7AA8, &lbl_27_bss_8BF0[3].ptr);

    lbl_27_bss_8BF0[4].data = (void*)(lbl_27_data_A2010 + 0xB20);
    __register_global_object(&lbl_27_bss_8BF0[4].data, fn_27_3C7A68, &lbl_27_bss_8BF0[4].ptr);

    lbl_27_bss_8BF0[5].data = (void*)(lbl_27_data_A2010 + 0xAA0);
    __register_global_object(&lbl_27_bss_8BF0[5].data, fn_27_3C7A28, &lbl_27_bss_8BF0[5].ptr);

    lbl_27_bss_8BF0[6].data = (void*)(lbl_27_data_A2010 + 0xA28);
    __register_global_object(&lbl_27_bss_8BF0[6].data, fn_27_3C79E8, &lbl_27_bss_8BF0[6].ptr);

    lbl_27_bss_8BF0[7].data = (void*)(lbl_27_data_A2010 + 0x9A8);
    __register_global_object(&lbl_27_bss_8BF0[7].data, fn_27_3C79A8, &lbl_27_bss_8BF0[7].ptr);
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_27_3C7BA8_ctor = (void*)fn_27_3C7BA8;
