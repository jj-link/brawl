typedef unsigned long size_t;

struct __OutStrCtrl {
    char* CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
};

extern void* memcpy(void* destination, const void* source, size_t count);

/* Truncation limits the copy, but does not stop the formatter's length count. */
void* __StringWrite(void* context, const char* data, size_t count) {
    struct __OutStrCtrl* control = (struct __OutStrCtrl*)context;
    size_t copied = control->CharsWritten + count <= control->MaxCharCount
                        ? count
                        : control->MaxCharCount - control->CharsWritten;

    memcpy(control->CharStr + control->CharsWritten, data, copied);
    control->CharsWritten += copied;
    return (void*)1;
}
