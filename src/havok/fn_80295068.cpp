#pragma force_active on
extern "C" {
void fn_80295068(void* obj, float f) {
    *(float*)((char*)obj + 0x18) = f;
    *(unsigned int*)obj = 0x090D001C;
}
}
