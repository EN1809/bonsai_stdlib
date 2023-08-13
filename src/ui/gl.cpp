
link_internal void
FramebufferTextureLayer(framebuffer *FBO, texture *Tex, debug_texture_array_slice Layer)
{
  u32 Attachment = FBO->Attachments++;
  GL.FramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + Attachment, Tex->ID, 0, Layer);
  return;
}

link_internal void
FlushBuffer(render_buffers_2d *TextGroup, textured_2d_geometry_buffer *Geo, v2 ScreenDim)
{
  GL.BindFramebuffer(GL_FRAMEBUFFER, 0);
  SetViewport(ScreenDim);
  GL.UseProgram(TextGroup->Text2DShader.ID);

  GL.ActiveTexture(GL_TEXTURE0);
  GL.BindTexture(GL_TEXTURE_2D_ARRAY, TextGroup->DebugTextureArray->ID);

  GL.Uniform1i(TextGroup->TextTextureUniform, 0); // Assign texture unit 0 to the TextTexureUniform

  u32 AttributeIndex = 0;
  BufferVertsToCard( TextGroup->SolidUIVertexBuffer, Geo, &AttributeIndex);
  BufferUVsToCard(   TextGroup->SolidUIUVBuffer,     Geo, &AttributeIndex);
  BufferColorsToCard(TextGroup->SolidUIColorBuffer,  Geo, &AttributeIndex);

  GL.Enable(GL_BLEND);
  GL.BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Draw(Geo->At);
  Geo->At = 0;

  GL.Disable(GL_BLEND);

  GL.DisableVertexAttribArray(0);
  GL.DisableVertexAttribArray(1);
  GL.DisableVertexAttribArray(2);

  AssertNoGlErrors;
}

link_internal void
FlushBuffer(render_buffers_2d *TextGroup, untextured_2d_geometry_buffer *Buffer, v2 ScreenDim)
{
  TIMED_FUNCTION();

  if (TextGroup)
  {
    GL.BindFramebuffer(GL_FRAMEBUFFER, 0);
    SetViewport(ScreenDim);
    UseShader(&TextGroup->SolidUIShader);

    u32 AttributeIndex = 0;
    BufferVertsToCard(TextGroup->SolidUIVertexBuffer, Buffer, &AttributeIndex);
    BufferColorsToCard(TextGroup->SolidUIColorBuffer, Buffer, &AttributeIndex);

    Draw(Buffer->At);
    Buffer->At = 0;

    GL.DisableVertexAttribArray(0);
    GL.DisableVertexAttribArray(1);

    AssertNoGlErrors;
  }
  else
  {
    Warn("FlushBuffer call issued without a RenderGroup!");
  }

  return;
}

link_internal void
FlushUIBuffers(renderer_2d *UiGroup, v2 ScreenDim)
{
  if (UiGroup->TextGroup)
  {
    FlushBuffer(UiGroup->TextGroup, &UiGroup->Geo, ScreenDim);
    FlushBuffer(UiGroup->TextGroup, &UiGroup->TextGroup->Geo, ScreenDim);
  }

  return;
}





link_internal shader
MakeRenderToTextureShader(memory_arena *Memory, m4 *ViewProjection)
{
  shader Shader = LoadShaders( CSz("RenderToTexture.vertexshader"), CSz("RenderToTexture.fragmentshader") );

  shader_uniform **Current = &Shader.FirstUniform;

  *Current = GetUniform(Memory, &Shader, ViewProjection, "ViewProjection");
  Current = &(*Current)->Next;

  return Shader;
}

#if 0
void AllocateGpuElementBuffer(gpu_mapped_element_buffer *GpuMap, u32 ElementCount);
void
InitRenderToTextureGroup(texture *DebugTextureArray, render_entity_to_texture_group *Group, memory_arena *PermMemory)
{
  AllocateGpuElementBuffer(&Group->GameGeo, (u32)Megabytes(4));

  Group->GameGeoFBO = GenFramebuffer();
  GL.BindFramebuffer(GL_FRAMEBUFFER, Group->GameGeoFBO.ID);

  FramebufferTextureLayer(&Group->GameGeoFBO, DebugTextureArray, DebugTextureArraySlice_Viewport);
  SetDrawBuffers(&Group->GameGeoFBO);
  Group->GameGeoShader = MakeRenderToTextureShader(PermMemory, &Group->ViewProjection);
  Group->Camera = Allocate(camera, PermMemory, 1);
  StandardCamera(Group->Camera, 10000.0f, 100.0f, {});

  GL.ClearColor(f32_MAX, f32_MAX, f32_MAX, f32_MAX);
  GL.ClearDepth(f32_MAX);
}
#endif

