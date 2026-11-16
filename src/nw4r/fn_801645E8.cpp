#pragma force_active on
extern "C" {
void* fn_8015C1B0(void*, void*);
void fn_80166CE8(void*);
void fn_801EC184(void*, void*);
}

extern "C" void fn_801645E8(void* self, void* out) {
    char* base = (char*)self;
    char* node;
    fn_801EC184(out, base + 0x54);
    node = 0;
    while ((node = (char*)fn_8015C1B0((void*)(base + 0x24), node)) != 0) {
        if (*(int*)(node + 0xF4) == 0) {
            fn_80166CE8(node);
        }
    }
}
