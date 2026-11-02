#pragma force_active on
#pragma push
#pragma opt_propagation off

extern "C" {

struct SoraMeleeObj {
    void* first_ptr;
    void* second_ptr;
    void* third_ptr;
    void* data_0C;
    void* ptr_10;
    void* unk_14;
    void* unk_18;
    void* data_1C;
};

extern SoraMeleeObj lbl_27_bss_7CD0;
extern char lbl_27_data_87E60[];
extern char lbl_27_data_87DE0[];
void* fn_27_32952C(void*, int);
void* fn_27_3294EC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_32956C() {
    SoraMeleeObj* base = &lbl_27_bss_7CD0;
    base->data_0C = (void*)lbl_27_data_87E60;
    
    void* (SoraMeleeObj::*member0) = &SoraMeleeObj::first_ptr;
    __register_global_object(&base->data_0C, (void*)fn_27_32952C, (void*)&(base->*member0));
    
    base->data_1C = (void*)lbl_27_data_87DE0;
    __register_global_object(&base->data_1C, (void*)fn_27_3294EC, &base->ptr_10);
}

}

#pragma pop

__declspec(section ".ctors") extern void* const fn_27_32956C_ctor = (void*)fn_27_32956C;
