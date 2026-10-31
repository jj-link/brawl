#pragma force_active on
extern "C" {
void *fn_116_9178(void *self, int arg);

void *fn_116_17CC4(char *self, int arg)
{
    switch (arg) {
    case 0:
        return self;
    case 1:
        return self + 0x488;
    case 2:
        return fn_116_9178(self, arg);
    default:
        return fn_116_9178(self, arg);
    }
}
}
