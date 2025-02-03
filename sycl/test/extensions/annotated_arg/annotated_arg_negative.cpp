// RUN: %clangxx -fsycl -ferror-limit=0 -fsycl-targets=%sycl_triple -fsyntax-only -Xclang -verify -Xclang -verify-ignore-unexpected=note,warning %s

#include "sycl/sycl.hpp"

using namespace sycl;
using namespace ext::oneapi::experimental;
using namespace ext::intel::experimental;

int main() {
  // check alignment property specified on non pointer type
  // expected-error@sycl/ext/oneapi/experimental/annotated_arg/annotated_arg.hpp:* {{Property alignment cannot be specified for annotated_arg<T> when T is a non pointer type.}}
  annotated_arg<int, decltype(properties{alignment<256>})> h;
  return 0;
}
