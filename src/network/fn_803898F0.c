#pragma force_active on

int fn_803898F0(void *arg0)
{
    int state;
    int result;

    if (*(int *)((char *)arg0 + 0x10) > 0) {
        return 2;
    }

    state = *(int *)((char *)arg0 + 0x4C);
    if (state == 3 || state == 0) {
        return 1;
    }

    result = 3;
    switch (state) {
    case 1:
        result = 0;
        break;
    }
    return result;
}
