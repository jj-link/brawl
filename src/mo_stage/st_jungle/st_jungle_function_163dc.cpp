#pragma force_active on
extern "C" {
extern char lbl_51_data_97C8[];
void __dl__FPv(void*);
void fn_51_289C(void*, int);

void* fn_51_163DC(void* self, int flag)
{
    if (self) {
        if (self) {
            char* p = (char*)self;
            *(void**)(p + 0x3c) = lbl_51_data_97C8;
            if (*(void**)(p + 0x174)) {
                __dl__FPv(*(void**)(p + 0x174));
            }
            *(void**)(p + 0x174) = 0;
            fn_51_289C(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
