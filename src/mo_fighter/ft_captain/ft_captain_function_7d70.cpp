#pragma force_active on
extern "C" {
void fn_100_6B88(void*, int);
extern unsigned char lbl_100_data_1710[];

void* fn_100_7D70(void* self, void* arg1, void* arg2, void* arg3,
                  void* arg4, void* arg5, void* arg6) {
    fn_100_6B88(self, 0);

    void* data = lbl_100_data_1710;
    *(void**)((char*)self + 0x8) = data;
    *(void**)self = (char*)data + 0x8;
    *(void**)((char*)self + 0xc) = arg1;
    *(void**)((char*)self + 0x10) = arg2;
    *(void**)((char*)self + 0x14) = arg3;
    *(void**)((char*)self + 0x18) = arg4;
    *(void**)((char*)self + 0x1c) = arg5;
    *(void**)((char*)self + 0x20) = arg6;

    return self;
}
}
