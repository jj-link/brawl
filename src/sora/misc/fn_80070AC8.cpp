#include <ms/ms_char_writer.h>
#pragma force_active on

extern "C" int lbl_805A01C8;
extern "C" void __ct__Q22ms10CharWriterFv(ms::CharWriter*);

extern "C" ms::CharWriter* fn_80070AC8(ms::CharWriter* self) {
    __ct__Q22ms10CharWriterFv(self);
    *(float*)((char*)self + 0x74) = 0.0f;
    *(float*)((char*)self + 0x78) = 0.0f;
    *(float*)((char*)self + 0x7C) = 640.0f;
    *(float*)((char*)self + 0x80) = 480.0f;
    *(float*)((char*)self + 0x88) = 0.0f;
    *(float*)((char*)self + 0x8C) = 0.0f;
    *(int*)((char*)self + 0x90) = 4;
    *(int*)((char*)self + 0x94) = 0;
    *(int**)((char*)self + 0x98) = &lbl_805A01C8;
    *(int*)((char*)self + 0x9C) = 0;
    return self;
}
