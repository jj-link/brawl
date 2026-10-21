#pragma force_active on
struct Info {
    char pad[0x10];
    int count;
};

struct Object {
    Info* info;
    char pad04[0x18];
    unsigned char* data;
    char pad20[8];
    unsigned char flag28;
    unsigned char flag29;
};

extern "C" void* fn_8032EF34(Object* p) {
    int count = p->info->count;
    for (int i = 0; i < count; ++i) {
        p->data[i] = 1;
    }
    p->flag29 = 0;
    p->flag28 = 1;
    return (char*)p + 0x10;
}
