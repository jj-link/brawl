#pragma force_active on
extern "C" void fn_95_7F30(void*, unsigned char);
extern "C" unsigned char lbl_95_data_8D60[];

extern "C" void* fn_95_16DD8(void* self, void* value) {
    fn_95_7F30(self, 0);
    *(void**)self = lbl_95_data_8D60;
    *(void**)((char*)self + 8) = value;
    *(int*)((char*)self + 12) = -1;
    return self;
}
