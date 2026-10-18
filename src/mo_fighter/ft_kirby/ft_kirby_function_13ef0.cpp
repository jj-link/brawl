#pragma force_active on
extern "C" {

struct Data_0x40 {
    unsigned char data[0x40];
};

struct Unknown {
    const struct Data_0x40 *field_0;
};

extern const struct Data_0x40 lbl_96_data_B1A4;

extern void fn_96_13EF0(struct Unknown *);

}

extern "C" void fn_96_13EF0(struct Unknown *r3)
{
    r3->field_0 = &lbl_96_data_B1A4;
}
