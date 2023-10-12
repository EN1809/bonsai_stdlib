global_variable const umm TempDebugOutputBufferSize = 64*1024;
global_variable char TempDebugOutputBuffer[TempDebugOutputBufferSize];

link_internal void
PrintToStdout(counted_string S);

link_internal void
SetupStdout(u32 ArgCount, const char** ArgStrings);

link_internal counted_string
FormatCountedString_(char* Dest, umm DestSize, const char *FS, ...);

#define CSz(NullTerminatedCString) \
  CS(NullTerminatedCString, sizeof(NullTerminatedCString)-1)

inline counted_string CS(cs *Cs) { return *Cs; }
inline counted_string CS(cs Cs) { return Cs; }

inline counted_string
CS(const char *S, umm Count)
{
  counted_string Result = {
    .Count = Count, .Start = S
  };
  return Result;
}


enum log_level
{
  LogLevel_Undefined,

  LogLevel_Verbose,
  LogLevel_Debug,
  LogLevel_Info,
  LogLevel_Error,
  LogLevel_Shush,
};

struct terminal_colors
{
  counted_string Red          = CSz("\x1b[31m");
  counted_string BrightRed    = CSz("\x1b[91m");
  counted_string DarkRed      = CSz("\x1b[38;5;88m");

  counted_string Blue         = CSz("\x1b[34m");
  counted_string BrightBlue   = CSz("\x1b[94m");
  counted_string Purple       = CSz("\x1b[35m");
  counted_string BrightPurple = CSz("\x1b[95m");
  counted_string Green        = CSz("\x1b[32m");
  counted_string BrightGreen  = CSz("\x1b[92m");
  counted_string Yellow       = CSz("\x1b[33m");
  counted_string BrightYellow = CSz("\x1b[93m");

  counted_string White        = CSz("\x1b[37m");
  counted_string Grey         = CSz("\x1b[38;5;242m");
};

global_variable terminal_colors TerminalColors = {};

#if 0
// TODO(Jesse): Metaprogram this?  ATM we only ever turn colors off
link_internal void
SetTerminalColorsOn()
{
  NotImplemented;
  /* TerminalColors.BrightRed    = CSz("\x1b[31m"); */
  /* TerminalColors.BrightBlue   = CSz("\x1b[34m"); */
  /* TerminalColors.BrightPurple = CSz("\x1b[35m"); */
  /* TerminalColors.BrightGreen  = CSz("\x1b[32m"); */
  TerminalColors.Red             = CSz("\x1b[31m");
  TerminalColors.Blue            = CSz("\x1b[34m");
  TerminalColors.Purple          = CSz("\x1b[35m");
  TerminalColors.Green           = CSz("\x1b[32m");
  TerminalColors.Yellow          = CSz("\x1b[33m");
  TerminalColors.BrightYellow    = CSz("\x1b[93m");
  TerminalColors.White           = CSz("\x1b[37m");
}
#endif

// TODO(Jesse): Metaprogram this
link_internal void
SetTerminalColorsOff()
{
#if 1
  TerminalColors.Red          = CSz("");
  TerminalColors.BrightRed    = CSz("");
  TerminalColors.DarkRed      = CSz("");

  TerminalColors.BrightBlue   = CSz("");
  TerminalColors.Blue         = CSz("");
  TerminalColors.Purple       = CSz("");
  TerminalColors.BrightPurple = CSz("");
  TerminalColors.Green        = CSz("");
  TerminalColors.BrightGreen  = CSz("");
  TerminalColors.Yellow       = CSz("");
  TerminalColors.BrightYellow = CSz("");
  TerminalColors.White        = CSz("");
  TerminalColors.Grey         = CSz("");
#endif
}

#define LogDirect(...) PrintToStdout(FormatCountedString_(TempDebugOutputBuffer, TempDebugOutputBufferSize, __VA_ARGS__))

#define InvalidCase(C) case C: {Error("Invalid case value (" #C ") " __FILE__ ":" STRINGIZE(__LINE__));} break
#define InvalidDefaultCase default: {Error("Invalid case value (default) " __FILE__ ":" STRINGIZE(__LINE__));} break

#define DEFAULT_FILE_IDENTIFIER  __FILE__ ":" STRINGIZE(__LINE__)

#define DebugChars(...) do {                  \
                                              \
  if (Global_LogLevel <= LogLevel_Debug) {    \
    LogDirect(__VA_ARGS__);                   \
  }                                           \
                                              \
} while (false)


#define DebugLine(...) do {                                                    \
                                                                               \
  if (Global_LogLevel <= LogLevel_Debug) {                                     \
    LogDirect(__VA_ARGS__);                                                    \
    LogDirect(Newline);                                                        \
  }                                                                            \
                                                                               \
} while (false)


#define DebugMessage(...) do {                                                 \
                                                                               \
  if (Global_LogLevel <= LogLevel_Debug) {                                     \
    LogDirect("%S   Debug   %S- ", TerminalColors.Blue, TerminalColors.White); \
    LogDirect(__VA_ARGS__);                                                    \
    LogDirect(Newline);                                                        \
  }                                                                            \
                                                                               \
} while (false)



#define Info(...) do {                                                           \
                                                                                 \
  if (Global_LogLevel <= LogLevel_Info) {                                        \
    LogDirect("%S   Info    %S- ", TerminalColors.Blue, TerminalColors.White);   \
    LogDirect(__VA_ARGS__);                                                      \
    LogDirect(Newline);                                                          \
  }                                                                              \
                                                                                 \
} while (false)



#define SoftError(...) do {                                                     \
                                                                                \
  if (Global_LogLevel <= LogLevel_Error) {                                      \
    LogDirect("%S ! Error   %S- ", TerminalColors.Red, TerminalColors.White);   \
    LogDirect(__VA_ARGS__);                                                     \
    LogDirect(Newline);                                                         \
  }                                                                             \
                                                                                \
} while (false)

#define Error(...) do {                                                         \
                                                                                \
  if (Global_LogLevel <= LogLevel_Error) {                                      \
    SoftError(__VA_ARGS__);                                                     \
    RuntimeBreak();                                                             \
  }                                                                             \
                                                                                \
} while (false)


#define Leak(...) do {                                                             \
                                                                                   \
  if (Global_LogLevel <= LogLevel_Error) {                                         \
    LogDirect("%S * Leaking %S- ", TerminalColors.Yellow, TerminalColors.White);   \
    LogDirect(__VA_ARGS__);                                                        \
    LogDirect(Newline);                                                            \
  }                                                                                \
                                                                                   \
} while (false)


#define BUG(...) do {                                                              \
                                                                                   \
  if (Global_LogLevel <= LogLevel_Error) {                                         \
    LogDirect("%S * BUG     %S- ", TerminalColors.Red, TerminalColors.White);      \
    LogDirect(__VA_ARGS__);                                                        \
    LogDirect(Newline);                                                            \
  }                                                                                \
                                                                                   \
} while (false)


#define Perf(...) do {                                                           \
                                                                                 \
  if (Global_LogLevel <= LogLevel_Info) {                                        \
    LogDirect("%S   Perf    %S- ", TerminalColors.Yellow, TerminalColors.White); \
    LogDirect(__VA_ARGS__);                                                      \
    LogDirect(Newline);                                                          \
  }                                                                              \
                                                                                 \
} while (false)

#define Warn(...) do {                                                             \
                                                                                   \
  if (Global_LogLevel <= LogLevel_Info) {                                          \
    LogDirect("%S * Warning %S- ", TerminalColors.Yellow, TerminalColors.White);   \
    LogDirect(__VA_ARGS__);                                                        \
    LogDirect(Newline);                                                            \
  }                                                                                \
                                                                                   \
} while (false)

#define LogSuccess(...) do {                                                      \
                                                                                  \
  if (Global_LogLevel <= LogLevel_Info) {                                       \
    LogDirect("%S   Success %S- ", TerminalColors.Green, TerminalColors.White);   \
    LogDirect(__VA_ARGS__);                                                       \
    LogDirect(Newline);                                                           \
  }                                                                               \
                                                                                  \
} while (false)

#define OpenGlDebugMessage(...) do {                                                            \
                                                                                                \
  if (Global_LogLevel <= LogLevel_Debug) {                                                      \
    LogDirect("%S * OpenGl Debug Message %S- ", TerminalColors.Yellow, TerminalColors.White);   \
    LogDirect(__VA_ARGS__);                                                                     \
    LogDirect(Newline);                                                                         \
  }                                                                                             \
                                                                                                \
} while (false)
