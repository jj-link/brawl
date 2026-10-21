#pragma force_active on
extern "C" {
void fn_801C7288(void* obj, void* ptr) {
    *(void**)((char*)obj + 0x28) = (void*)((char*)ptr + 8);
}
}
