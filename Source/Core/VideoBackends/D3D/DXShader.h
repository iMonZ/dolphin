// Copyright 2017 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once
#include <memory>

#include "VideoBackends/D3D/D3DBase.h"
#include "VideoBackends/D3DCommon/Shader.h"

namespace DX11
{
class DXShader final : public D3DCommon::Shader
{
public:
  DXShader(ShaderStage stage, BinaryData bytecode, ID3D11DeviceChild* shader);
  ~DXShader() override;

  const BinaryData& GetByteCode() const { return m_bytecode; }

  ID3D11VertexShader* GetD3DVertexShader() const;
  ID3D11GeometryShader* GetD3DGeometryShader() const;
  ID3D11PixelShader* GetD3DPixelShader() const;
  ID3D11ComputeShader* GetD3DComputeShader() const;

  static std::unique_ptr<DXShader> CreateFromBytecode(ShaderStage stage, BinaryData bytecode);

private:
  ComPtr<ID3D11DeviceChild> m_shader;
};

}  // namespace DX11
