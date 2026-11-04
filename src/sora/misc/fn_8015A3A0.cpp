#pragma force_active on
struct Object {
    char pad[8];
    char* data;
};

extern "C" void* fn_8015B3CC(char*);
extern "C" void* fn_8015B4BC(char*, int);

extern "C" void fn_8015A3A0(Object* self, int index, void** out1, void** out2) {
    *out1 = 0;
    *out2 = 0;
    if (self->data) {
        *out1 = fn_8015B3CC(self->data);
        *out2 = fn_8015B4BC(self->data, index);
    }
}