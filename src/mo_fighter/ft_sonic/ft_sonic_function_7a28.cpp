#pragma force_active on
extern "C" {
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
extern char lbl_123_data_133C[];
void* fn_123_7A28(void* self, void* a, void* b, void* c);
}

void* fn_123_7A28(void* self, void* a, void* b, void* c)
{
    char* s = (char*)self;
    *(void**)self = lbl_123_data_133C;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)(s + i * 8 + 4));
    }
    fn_27_561E0(s + 0x14, a, self, b, 1, true, c);
    return self;
}
