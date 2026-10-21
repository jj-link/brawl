#pragma force_active on
extern "C" {
void fn_80294C28(void* obj, float val) {
    *(float*)((char*)obj + 0x4) = val;
    *(unsigned int*)obj = 0x040C0008;
}
}
