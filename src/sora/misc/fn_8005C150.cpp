#pragma force_active on
extern "C" {
void fn_8005C150(void* arg0, void* arg1) {
    *(int*)((char*)arg1 + 8) += 0x10000;
}
}
