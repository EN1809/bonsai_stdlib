bonsai_function b32
SearchForProjectRoot(void)
{
  b32 Result = FileExists(".root_marker");

  b32 ChdirSuceeded = True;
  b32 NotAtFilesystemRoot = True;

  /* ChdirSuceeded = (_chdir("/home/scallywag/bonsai") == 0); */
  while (!Result && ChdirSuceeded && NotAtFilesystemRoot)
  {
    ChdirSuceeded = (_chdir("..") == 0);
    NotAtFilesystemRoot = (!IsFilesystemRoot(GetCwd()));
    Result = FileExists(".root_marker");
  }

  return Result;
}
