#pragma force_active on
extern "C" {
void* fn_113_9E30(void* arg, int kind);

void* fn_113_9F1C(void* arg, int kind)
{
    switch (kind) {
    case 0:
        return arg;
    case 1:
        return (char*)arg + 0x47C;
    case 2:
        return fn_113_9E30(arg, kind);
    default:
        break;
    }
    return fn_113_9E30(arg, kind);
}
}
