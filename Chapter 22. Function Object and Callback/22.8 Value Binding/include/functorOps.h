#ifndef FUNCTOR_OPS_H_
#define FUNCTOR_OPS_H_

// 定义func_ptr()，FunctionPtr和FunctionPtrT
#include "../../22.6 Introspection/include/6funcPtr.h"

// 定义Composer<>
#include "../../22.7 Functor Composition/include/compose6.h"

// 定义辅助函数compose()
#include "../../22.7 Functor Composition/include/composeConv.h"

// 定义Binder<>
// -包含定义BoundVal()和StaticBoundVal<>的boundVal.h
// -包含定义ForwardParamT<>的forwardParam.h
// -包含定义FunctorParam<>的functorParam.h
// -包含定义BinderParams<>的binderParams.h
// -包含定义SignSelectT<>的signSelect.h
#include "binder5.h"

// 定义辅助函数bind()和bindfp()
#include "bindConv.h"
#include "bindFp1.h"
#include "bindFp2.h"
#include "bindFp3.h"

#endif	// FUNCTOR_OPS_H_
