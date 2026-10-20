#pragma force_active on
extern "C" void fn_27_5C7AC(void* self);
extern "C" unsigned char lbl_27_data_6F30[];

extern "C" void* fn_27_61454(void* self) {
    fn_27_5C7AC(self);
    *(void**)((char*)self + 0x08) = lbl_27_data_6F30;
    *(void**)self = lbl_27_data_6F30 + 0x08;
    *(void**)((char*)self + 0x0C) = lbl_27_data_6F30 + 0xD8;
    *(void**)((char*)self + 0x18) = lbl_27_data_6F30 + 0xF0;
    *(void**)((char*)self + 0x24) = lbl_27_data_6F30 + 0x100;
    *(void**)((char*)self + 0x30) = lbl_27_data_6F30 + 0x10C;
    *(unsigned int*)((char*)self + 0xAC) = 24;
    *(unsigned int*)((char*)self + 0xB4) = 24;
    return self;
}
