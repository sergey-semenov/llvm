//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#pragma once

#include "MockDeviceImage.hpp"
#include "MockKernelInfo.hpp"

class TestKernel;

namespace sycl {
inline namespace _V1 {
namespace detail {
template <>
struct KernelInfo<TestKernel>
    : public unittest::MockKernelInfoBase {
  static constexpr const char *getName() { return "TestKernel"; }
  static constexpr const char *getFileName() { return "TestKernel.hpp"; }
  static constexpr const char *getFunctionName() {
    return "TestKernelFunctionName";
  }
  static constexpr unsigned getLineNumber() { return 13; }
  static constexpr unsigned getColumnNumber() { return 8; }
};

} // namespace detail
} // namespace _V1
} // namespace sycl

static sycl::unittest::MockDeviceImage Img =
    sycl::unittest::generateDefaultImage({"TestKernel"});
static sycl::unittest::MockDeviceImageArray<1> ImgArray{&Img};
