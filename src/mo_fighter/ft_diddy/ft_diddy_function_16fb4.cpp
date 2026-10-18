#pragma force_active on
struct DiddyCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_115_16FB4(void* object, int flag)
{
    DiddyCallbackFlags* flags =
        reinterpret_cast<DiddyCallbackFlags*>(static_cast<unsigned char*>(object) + 0xA4);

    flags->selected = (unsigned char)(flag & 1);
}
