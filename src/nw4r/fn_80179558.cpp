#pragma force_active on
extern "C" int fn_80179558(void* arg0, void* arg1) {
    return *(int*)((char*)arg1 + *(unsigned short*)((char*)arg0 + 0x42));
}
