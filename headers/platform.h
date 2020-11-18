#if _WIN32
#include <win32_platform.h>
#elif BONSAI_LINUX
#include <unix_platform.h>
#elif EMCC
#include <wasm_platform.h>
#else
#error "Unknown Platform!"
#endif
