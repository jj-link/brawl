#pragma force_active on
extern "C" {
void fn_8005BEB0(int unused, void* arg) {
    *(int*)((char*)arg + 8) += 0x10000;
}
}
