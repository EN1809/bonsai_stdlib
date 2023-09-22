
link_internal void
PlatformInit(platform *Plat, memory_arena *Memory)
{
  Plat->Memory = Memory;

  u32 LogicalCoreCount = PlatformGetLogicalCoreCount();
  u32 WorkerThreadCount = GetWorkerThreadCount();
  s32 TotalThreadCount  = (s32)GetTotalThreadCount();
  Info("Detected %u Logical cores, creating %u threads", LogicalCoreCount, WorkerThreadCount);

  Plat->Threads = Allocate(thread_startup_params, Plat->Memory, TotalThreadCount);

#if BONSAI_NETWORK_IMPLEMENTATION
  Plat->ServerState = ServerInit(GameMemory);
#endif

  return;
}

enum bonsai_init_flags
{
  BonsaiInit_Default = 0,

  BonsaiInit_LaunchThreadPool = (1 << 0),
  BonsaiInit_OpenWindow       = (1 << 1),
};


link_internal b32
InitializeBonsaiStdlib(bonsai_init_flags Flags, os *Os, platform *Plat, engine_resources *Engine, memory_arena *Memory)
{
  Info("Initializing Bonsai");

  Assert(ThreadLocal_ThreadIndex == -1);
  SetThreadLocal_ThreadIndex(0);

  PlatformInit(Plat, Memory);

  if (Flags & BonsaiInit_LaunchThreadPool)
  {
     Global_ThreadStates = Initialize_ThreadLocal_ThreadStates((s32)GetTotalThreadCount(), Engine, Memory);
  }

  if (Flags & BonsaiInit_OpenWindow)
  {
    s32 VSyncFrames = 0;
    if (!OpenAndInitializeWindow(Os, Plat, VSyncFrames)) { Error("Initializing Window :( "); return False; }
    Assert(Os->GlContext);

    Ensure( InitializeOpenglFunctions() );
  }

  return True;
}
