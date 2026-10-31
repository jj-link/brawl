#pragma force_active on
extern "C" void *fn_116_9178(void *self, int i);

extern "C" void *fn_116_9264(void *self, int i)
{
    switch (i)
    {
        case 0:
            return self;
        case 1:
            return (char *)self + 0x470;
        case 2:
            return fn_116_9178(self, i);
        default:
            return fn_116_9178(self, i);
    }
}