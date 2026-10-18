#pragma force_active on
extern "C" {
void operator delete(void* p);
}

extern "C" void* fn_94_4AAC(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
