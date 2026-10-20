#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" char lbl_27_data_57300[];
extern "C" const float lbl_27_rodata_43E8;

struct grGimmickLadder {
    grGimmickLadder(const char* name);
};

grGimmickLadder::grGimmickLadder(const char* name) {
    __ct__10grYakumonoFPCc(this, name);
    float z = lbl_27_rodata_43E8;
    *(int*)((char*)this + 0x150) = 0;
    *(char**)((char*)this + 0x3c) = lbl_27_data_57300;
    *(int*)((char*)this + 0x17c) = 0;
    *(int*)((char*)this + 0x180) = 0;
    *(float*)((char*)this + 0x188) = z;
    *(float*)((char*)this + 0x18c) = z;
    *(float*)((char*)this + 0x190) = z;
    *(float*)((char*)this + 0x194) = z;
    *(float*)((char*)this + 0x198) = z;
    *(float*)((char*)this + 0x19c) = z;
    *(int*)((char*)this + 0xe4) = 0;
}
