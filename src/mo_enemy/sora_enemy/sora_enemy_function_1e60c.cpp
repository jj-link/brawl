#pragma force_active on
extern "C" float fn_41_1E60C(float current, float candidate)
{
    int truncated = (int)candidate;

    if (truncated == 35791)
        return current;

    truncated = (int)candidate;
    if (truncated == 35795)
        return current;

    if (current > candidate)
        current = candidate;

    return current;
}
