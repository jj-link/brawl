#pragma force_active on
extern "C" {
void fn_27_19A05C(void*, int, int);
void fn_27_6A244(void*, void*, void*);
}

extern "C" void* fn_101_9FD0(void* object, void* arg) {
    unsigned char* members = static_cast<unsigned char*>(object);
    fn_27_19A05C(object, 8, 0);
    fn_27_6A244(members + 0x1AC, arg, object);
    return object;
}
