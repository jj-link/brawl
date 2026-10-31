#pragma force_active on
extern "C" void update__7IpHumanFv(void *);

extern "C" void fn_27_12472C(void *arg)
{
    void *human = *(void **)((char *)arg + 0x0C);
    if (human == 0)
        return;

    char *fighter = (char *)(*(void **)((char *)arg + 0x04));
    if ((unsigned char)fighter[0x0F] != 6)
        update__7IpHumanFv(human);
}
