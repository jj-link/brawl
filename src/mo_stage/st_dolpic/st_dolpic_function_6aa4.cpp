#pragma force_active on
extern "C" {
extern char lbl_46_data_1FB0[];
void* fn_46_4570(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_46_6AA4(void* self, int flag) {
    if (self != 0) {
        char* s = (char*)self;
        *(void**)(s + 0x3C) = (void*)lbl_46_data_1FB0;
        void* obj = *(void**)(s + 0x44);
        void* p = *(void**)obj;
        if (p != 0) {
            *(int*)((char*)p + 0xD4) = 0;
        }
        fn_46_4570(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
