#pragma force_active on
extern "C" {
void* fn_93_12D0C(void* p, short flag);
}

void operator delete(void* p);

extern "C" void* fn_93_12D0C(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
