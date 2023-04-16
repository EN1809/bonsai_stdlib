struct thread_startup_params;
struct graphics;
struct server_state;
struct platform
{
  work_queue LowPriority;
  work_queue HighPriority;

  volatile u32 HighPriorityWorkerCount;

  bonsai_futex HighPriorityModeFutex;
  bonsai_futex WorkerThreadsSuspendFutex;
  bonsai_futex WorkerThreadsExitFutex;

  thread_startup_params *Threads;

  v2 MouseP;
  v2 MouseDP;

  memory_arena *Memory;

  r64 GameTime;

  r32 dt;
  s32 WindowWidth;
  s32 WindowHeight;

  input Input;

  server_state *ServerState;
};

