#pragma force_active on

extern "C" {
extern const float lbl_66_rodata_1B8;
extern char lbl_66_data_2518[0x90];

void fn_66_9940(void*);
void fn_66_9950(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct StEarthOwner {
    char pad[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int unused3c : 27;
    unsigned int flags3c : 5;
    unsigned int pad40;
    void* table0;
    void* table1;
    unsigned int flags4c : 13;
    unsigned int unused4c : 19;
    char entries[0x38];
};

extern "C" StEarthOwner* fn_66_97B4(StEarthOwner* self) {
    self->x = lbl_66_rodata_1B8;
    self->y = lbl_66_rodata_1B8;
    self->z = lbl_66_rodata_1B8;
    self->flags3c = 0;
    self->table0 = lbl_66_data_2518;
    self->table1 = lbl_66_data_2518 + 0x48;
    self->flags4c = 0;
    __construct_array(self->entries,
                      (void (*)(void*))fn_66_9940,
                      (void (*)(void*))fn_66_9950,
                      8, 7);
    return self;
}
