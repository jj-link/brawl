#pragma force_active on
struct Work { int word[4]; };

extern "C" void fn_101_D4FC(Work *const *work, int value, unsigned int index)
{
    Work *w = work[3];

    w->word[index] = value;
}
