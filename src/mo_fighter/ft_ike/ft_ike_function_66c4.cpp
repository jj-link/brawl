#pragma force_active on
struct IkeAnimCommand {
    unsigned char pad[0x24];
};

extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void fn_27_1AB96C(void*, unsigned char);

extern "C" IkeAnimCommand* fn_119_66C4(IkeAnimCommand* object, int event)
{
    fn_27_711E4(object, (short)event, object + 1);
    fn_27_1AB96C(object + 1, 0);
    return object;
}
