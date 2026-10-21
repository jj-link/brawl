#pragma force_active on

extern "C" void fn_80286F98(void*, void*, void*);

extern "C" void fn_802E4418(void* arg0, void* arg1) {
    fn_80286F98(arg1, reinterpret_cast<unsigned char*>(arg0) + 0x10, arg0);
}
