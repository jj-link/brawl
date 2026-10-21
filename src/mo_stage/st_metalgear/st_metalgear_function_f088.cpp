#pragma force_active on
extern "C" {
extern const float lbl_71_rodata_23C[];
extern unsigned char lbl_71_data_3B68[];

void fn_71_9554(void*);
void* fn_71_9564(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct Object {
    char pad[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int preserved : 27;
    unsigned int flags : 5;
    unsigned int unk40;
    void* data;
    void* dataEnd;
    unsigned int flags4C : 13;
    unsigned int preserved4C : 19;
    char array[56];
};

extern "C" void* fn_71_F088(Object* p) {
    float f = lbl_71_rodata_23C[0];
    p->x = f;
    p->y = f;
    p->z = f;
    p->flags = 0;
    p->data = lbl_71_data_3B68;
    p->dataEnd = lbl_71_data_3B68 + 0x48;
    p->flags4C = 0;
    __construct_array(p->array, fn_71_9554,
                      (void (*)(void*))fn_71_9564, 8, 7);
    return p;
}
