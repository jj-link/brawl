#pragma force_active on
extern "C" {

void __dl__FPv(void*);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dt__14snd3DGeneratorFv(void*, int);
void fn_50_2034(void*, int);

void* lbl_50_data_2480[];

void* fn_50_89C0(void* this_ptr, int flag) {
    if (this_ptr) {
        char* obj = (char*)this_ptr;
        void* ptr = *(void**)(obj + 0x17c);
        *(void**)(obj + 0x3c) = &lbl_50_data_2480;
        if (ptr) {
            __dl__FPv(ptr);
        }
        *(void**)(obj + 0x17c) = 0;
        
        void* seq_addr = obj + 0x1a0;
        if (seq_addr) {
            __dt__Q28StSeUtil5SeSeqFv(seq_addr, 0);
        }
        
        __dt__14snd3DGeneratorFv(obj + 0x190, -1);
        
        fn_50_2034(this_ptr, 0);
        
        if (flag > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}

}
