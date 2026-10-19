#pragma force_active on
extern "C" {
void __ct__9grGimmickFPCc(void*, const char*);
extern unsigned char lbl_40_data_3CD8[];

void* fn_40_19B44(void* self, const char* name) {
    __ct__9grGimmickFPCc(self, name);
    *(unsigned int*)((char*)self + 0x14c) = 0;
    *(unsigned int*)((char*)self + 0x3c) = (unsigned int)lbl_40_data_3CD8;
    *(unsigned int*)((char*)self + 0xe4) = 0;
    return self;
}
}
