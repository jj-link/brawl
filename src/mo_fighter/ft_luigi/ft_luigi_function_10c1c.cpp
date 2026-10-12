class soArticleMediatorNull;

extern "C" bool fn_99_10930(const soArticleMediatorNull*);

extern "C" bool fn_99_10C1C(const void* receiver) {
    return fn_99_10930(reinterpret_cast<const soArticleMediatorNull*>(
        static_cast<const char*>(receiver) - 4));
}
