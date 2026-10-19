#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_126_data_5340[];

extern "C" void* fn_126_B790(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x33);
    unsigned char* data = lbl_126_data_5340;
    *(void**)((char*)self + 8) = data;
    *(void**)self = data + 8;
    return self;
}
