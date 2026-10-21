#pragma force_active on
extern "C" int lbl_805A01F8;
extern "C" void OSSendMessage(void* queue, void* msg, int flags);

extern "C" void PrepareReady__Fb(bool flag) {
    OSSendMessage((void*)(lbl_805A01F8 + 0x7a0), (void*)flag, 1);
}
