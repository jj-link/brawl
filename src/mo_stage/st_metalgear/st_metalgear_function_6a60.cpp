#pragma force_active on
extern const float lbl_71_rodata_168;

class Class_2930 {
public:
    virtual void fn_71_D0F4();
    virtual void fn_71_C5BC();
    virtual void fn_71_C5CC();
    virtual void fn_71_A130();
    virtual void fn_71_9D70();
    virtual void fn_71_94BC();
    virtual float fn_71_C8C0();
};

struct Entry {
    char pad[0xC];
    Class_2930* obj;
};

struct Owner {
    char pad[0x48];
    Entry** table;
};

extern "C" float fn_71_6A60(Owner* self, unsigned int idx)
{
    float r;
    Entry* e = self->table[idx];
    if (e == 0) {
        r = lbl_71_rodata_168;
    } else {
        r = e->obj->fn_71_C8C0();
    }
    return r;
}
