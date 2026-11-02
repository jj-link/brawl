#pragma force_active on
#pragma push
#pragma opt_propagation off
extern "C" void __register_global_object(void*, void* (*)(void*, int), void*);
extern "C" void* fn_27_2FC57C(void*, int);
extern "C" void* fn_27_2FC5BC(void*, int);
extern "C" void* fn_27_2FC5FC(void*, int);
extern "C" void* fn_27_2FC63C(void*, int);
extern "C" void* fn_27_2FC67C(void*, int);

extern "C" unsigned char lbl_27_bss_75B8[];
extern "C" unsigned char lbl_27_data_80750[];

extern "C" void fn_27_2FC6BC() {
    struct Entry {
        void* ptr;
        int unk4;
        int unk8;
        void* data;
    };
    
    Entry* entries = (Entry*)lbl_27_bss_75B8;
    unsigned char* data = lbl_27_data_80750;
    
    void* (Entry::*firstPtr) = &Entry::ptr;
    
    entries[0].data = (void*)(data + 0x8D0);
    __register_global_object(&entries[0].data, fn_27_2FC67C, &(entries[0].*firstPtr));
    
    entries[1].data = (void*)(data + 0x850);
    __register_global_object(&entries[1].data, fn_27_2FC63C, &entries[1].ptr);
    
    entries[2].data = (void*)(data + 0x7D0);
    __register_global_object(&entries[2].data, fn_27_2FC5FC, &entries[2].ptr);
    
    entries[3].data = (void*)(data + 0x750);
    __register_global_object(&entries[3].data, fn_27_2FC5BC, &entries[3].ptr);
    
    entries[4].data = (void*)(data + 0x6D0);
    __register_global_object(&entries[4].data, fn_27_2FC57C, &entries[4].ptr);
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_27_2FC6BC_ctor = (void*)fn_27_2FC6BC;
