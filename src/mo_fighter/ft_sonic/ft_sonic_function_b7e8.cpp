#pragma force_active on
extern "C" void* fn_123_396C(void*, short);

extern "C" {
void* fn_123_B7E8(void* p, short flag);
}

void operator delete(void*);

extern "C" void* fn_123_B7E8(void* p, short flag) {
    if (p != 0) {
        fn_123_396C(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
