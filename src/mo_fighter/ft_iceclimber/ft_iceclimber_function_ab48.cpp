#pragma force_active on
extern "C" int fn_105_AB48(int value)
{
    if (value >= 4)
        goto check_six;

    if (value == 1)
        goto yes;

    goto no;

check_six:
    if (value >= 6)
        goto no;

yes:
    return 1;

no:
    return 0;
}
