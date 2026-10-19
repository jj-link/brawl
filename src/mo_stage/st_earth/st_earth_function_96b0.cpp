#pragma force_active on
extern "C" {
void fn_66_9940(void*);
void fn_66_9950(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" char lbl_66_data_2840[0x90];

struct StEarthArrayOwner {
    char m_pad[0x28];
    void* m_table0;
    void* m_table1;
    unsigned int m_flags;
    char m_entries[0x30];
};

extern "C" StEarthArrayOwner* fn_66_96B0(StEarthArrayOwner* self) {
    self->m_table0 = lbl_66_data_2840;
    self->m_table1 = lbl_66_data_2840 + 0x48;
    self->m_flags = self->m_flags & 0x0007FFFF;
    __construct_array(self->m_entries, (void (*)(void*))fn_66_9940, (void (*)(void*))fn_66_9950, 8, 6);
    return self;
}
