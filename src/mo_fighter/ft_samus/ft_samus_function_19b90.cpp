#pragma force_active on
typedef unsigned int u32;
typedef int ftKind;

struct ftExtendParamAccesser {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

extern "C" ftExtendParamAccesser* __ct__21ftExtendParamAccesserF6ftKind(
    ftExtendParamAccesser*, ftKind);

extern "C" unsigned char lbl_94_data_9BBC[];

extern "C" ftExtendParamAccesser* fn_94_19B90(ftExtendParamAccesser* accesser) {
    __ct__21ftExtendParamAccesserF6ftKind(accesser, 0x18);
    accesser->unk08 = (u32)lbl_94_data_9BBC;
    accesser->unk00 = (u32)lbl_94_data_9BBC + 8;
    return accesser;
}
