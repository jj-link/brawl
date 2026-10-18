#pragma force_active on
struct soArrayVTableStub {
    void* entries[16];
};

extern "C" {
extern const void* lbl_114_data_A280[16];

void fn_114_1A18C(void** vtable)
{
    *vtable = (void*)lbl_114_data_A280;
}
}
