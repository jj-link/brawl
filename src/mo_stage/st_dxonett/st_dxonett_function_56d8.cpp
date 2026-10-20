#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flags;
} FlagsStruct;

extern "C" void fn_78_56D8(FlagsStruct *arg0)
{
    /* Set the bit corresponding to FPSCR bit 25 (0x02000000): switch to
       "round to nearest" rounding mode. */
    arg0->flags |= 0x02000000;
}
