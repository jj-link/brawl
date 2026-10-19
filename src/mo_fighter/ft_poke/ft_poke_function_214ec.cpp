#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_116_data_99BC[];

extern "C" void* fn_116_214EC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x1f);
    *(void**)((char*)self + 8) = lbl_116_data_99BC;
    *(void**)self = lbl_116_data_99BC + 8;
    return self;
}
