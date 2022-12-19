#pragma once

#include "CdeclFunctionInvoker.h"
#include "FastcallFunctionInvoker.h"
#include "StdcallFunctionInvoker.h"
#include <Platform/Macros/CallingConventions.h>
#include <Platform/Macros/IsPlatform.h>

template <typename FunctionType>
struct FunctionInvoker {};

template <typename ReturnType, typename... Args>
struct FunctionInvoker<ReturnType FASTCALL_CONV (Args...)> : FastcallFunctionInvoker<ReturnType, Args...> {
    using FastcallFunctionInvoker<ReturnType, Args...>::FastcallFunctionInvoker;
};

#if IS_WIN32()

template <typename ReturnType, typename... Args>
struct FunctionInvoker<ReturnType STDCALL_CONV (Args...)> : StdcallFunctionInvoker<ReturnType, Args...> {
    using StdcallFunctionInvoker<ReturnType, Args...>::StdcallFunctionInvoker;
};

template <typename ReturnType, typename... Args>
struct FunctionInvoker<ReturnType CDECL_CONV (Args...)> : CdeclFunctionInvoker<ReturnType, Args...> {
    using CdeclFunctionInvoker<ReturnType, Args...>::CdeclFunctionInvoker;
};

#endif
