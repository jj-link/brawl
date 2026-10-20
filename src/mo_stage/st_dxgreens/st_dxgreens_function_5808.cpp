#pragma force_active on
struct Word8 { unsigned int pad[2]; unsigned int field0 : 6; };

extern "C" void fn_79_5808(Word8 *p, unsigned int v)
{
    p->field0 = v;
}
