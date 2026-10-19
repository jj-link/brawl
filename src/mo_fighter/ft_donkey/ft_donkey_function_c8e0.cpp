#pragma force_active on
struct ftExtendParamAccesser {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

extern "C" void* __ct__21ftExtendParamAccesserF6ftKind(
    ftExtendParamAccesser*, int);

extern "C" unsigned char lbl_92_data_8[];

extern "C" ftExtendParamAccesser* fn_92_C8E0(ftExtendParamAccesser* object) {
    __ct__21ftExtendParamAccesserF6ftKind(object, 1);
    object->unk8 = (unsigned int)lbl_92_data_8;
    object->unk0 = (unsigned int)(lbl_92_data_8 + 8);
    return object;
}
