#pragma force_active on
struct Data {
    unsigned char pad[0x10];
    int offset;
};

struct Handle {
    Data* data;
};

extern "C" void* fn_8018CF30(void**, const char*);

extern "C" void* fn_8018ECCC(const Handle* self, const char* name)
{
    Data* base = self->data;
    int offset = base->offset;
    void* data = offset ? (char*)base + offset : 0;
    return fn_8018CF30(&data, name);
}
