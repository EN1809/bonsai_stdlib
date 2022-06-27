#define CAssert(condition) static_assert((condition), #condition )

#if BONSAI_INTERNAL

#  define Ensure(condition) Assert((condition))

#  define Assert(condition)                                                  \
    do {                                                                     \
      if (!(condition)) {                                                    \
        LogDirect("%S ! Assert%S  - Failed" Newline,                         \
                  TerminalColors.Red,                                        \
                  TerminalColors.White);                                     \
                                                                             \
        LogDirect(" %S!%S         - %s during %s()" Newline,                        \
                  TerminalColors.Red,                                        \
                  TerminalColors.White,                                      \
                  #condition,                                                \
                  __FUNCTION__);                                             \
                                                                             \
        LogDirect(" %S!%S         - %s:%u:0" Newline,                        \
                  TerminalColors.Red,                                        \
                  TerminalColors.White,                                      \
                  __FILE__,                                                  \
                  __LINE__);                                                 \
                                                                             \
        RuntimeBreak();                                                      \
      }                                                                      \
    } while (false)

#  define InvalidCodePath() Error("Invalid Code Path - Panic!"); Assert(False)

#  define RuntimeBreak() do {                                                       \
  if (Global_DoRuntimeBreak) {\
    LogDirect("\n\n %S! Break%S\n", TerminalColors.Red, TerminalColors.White);       \
    PLATFORM_RUNTIME_BREAK();\
  } else {   \
    DebugLine("   Break   - Skipped");       \
  } \
} while (false)

#define NotImplemented Error("Implement Me!"); Assert(False)

#else // Release Build

#define Ensure(condition) condition
#define Assert(...)
#define InvalidCodePath(...)
#define RuntimeBreak(...)
#define NotImplemented Implement Meeeeee!!!

#endif
