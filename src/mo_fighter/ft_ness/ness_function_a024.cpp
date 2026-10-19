#pragma force_active on
extern "C" {
void fn_27_1999C4(void*, int, int);
void fn_27_19BF3C(void*, int, int);
void fn_27_150320(void*, void*, short, void*, void*);
}

extern "C" void* fn_101_A024(void* self, void* arg2, short arg3) {
    unsigned char* obj = static_cast<unsigned char*>(self);
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(obj + 0x584, 2, 0);
    fn_27_150320(obj + 0x5B8, arg2, arg3, self, obj + 0x584);
    return self;
}
