#pragma force_active on
extern "C" void operator_delete_dummy();

void operator delete(void* p);

extern "C" void* fn_122_1F934(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
