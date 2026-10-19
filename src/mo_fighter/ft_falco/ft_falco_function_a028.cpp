#pragma force_active on
extern "C" void fn_27_12DCA8(void);

struct Fighter
{
    unsigned char pad[0x1D090];
};

extern "C" void fn_108_A028(Fighter* fighter)
{
    fn_27_12DCA8();
    fighter->pad[0x1D091] = 0;
    fighter->pad[0x1D090] = 0;
}
